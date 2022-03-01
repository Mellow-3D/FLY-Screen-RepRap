/*
 * pcm.hpp
 *
 *  Created on: 2019年2月13日
 *      Author: Administrator
 */

#ifndef JNI_ACTIVITY_PCM_HPP_
#define JNI_ACTIVITY_PCM_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <limits.h>

#include <linux/ioctl.h>
#define __force
#define __bitwise
#define __user
#include <sound/asound.h>

// 超级精简版tinyalsa，就是这么简单
// 限制：采样率必须是48K，不接受其他采样率，否则报硬件设置参数错误
// /dev/snd/pcmC0D0p只能打开一次，因此不能有多个pcm的实例
// 音量调节由软件完成，主音量通过mixer完成，或者用ZKMediaPlayer调用setVolume一次。否则没有声音。
// flags根本没有作用，不使用mmap，没有irq，没有norestart，没有单调
// 格式只支持16位有符号双声道

struct pcm;

#define PCM_OUT        0x00000000

/* PCM runtime states */
#define	PCM_STATE_OPEN		0
#define	PCM_STATE_SETUP		1
#define	PCM_STATE_PREPARED	2
#define	PCM_STATE_RUNNING		3
#define	PCM_STATE_XRUN		4
#define	PCM_STATE_DRAINING	5
#define	PCM_STATE_PAUSED		6
#define	PCM_STATE_SUSPENDED	7
#define	PCM_STATE_DISCONNECTED	8

/* Bit formats */
enum pcm_format {
    PCM_FORMAT_S16_LE = 0,
    PCM_FORMAT_S32_LE,
    PCM_FORMAT_S8,
    PCM_FORMAT_S24_LE,

    PCM_FORMAT_MAX,
};

/* Configuration for a stream */
struct pcm_config {
    unsigned int channels;
    unsigned int rate;
    unsigned int period_size;
    unsigned int period_count;
    enum pcm_format format;

    /* Values to use for the ALSA start, stop and silence thresholds.  Setting
     * any one of these values to 0 will cause the default tinyalsa values to be
     * used instead.  Tinyalsa defaults are as follows.
     *
     * start_threshold   : period_count * period_size
     * stop_threshold    : period_count * period_size
     * silence_threshold : 0
     */
    unsigned int start_threshold;
    unsigned int stop_threshold;
    unsigned int silence_threshold;

    int avail_min;
};

/* PCM parameters */
enum pcm_param {
    PCM_PARAM_SAMPLE_BITS,
    PCM_PARAM_FRAME_BITS,
    PCM_PARAM_CHANNELS,
    PCM_PARAM_RATE,
    PCM_PARAM_PERIOD_TIME,
    PCM_PARAM_PERIOD_SIZE,
    PCM_PARAM_PERIOD_BYTES,
    PCM_PARAM_PERIODS,
    PCM_PARAM_BUFFER_TIME,
    PCM_PARAM_BUFFER_SIZE,
    PCM_PARAM_BUFFER_BYTES,
    PCM_PARAM_TICK_TIME,
};

/* Mixer control types */
enum mixer_ctl_type {
    MIXER_CTL_TYPE_BOOL,
    MIXER_CTL_TYPE_INT,
    MIXER_CTL_TYPE_ENUM,
    MIXER_CTL_TYPE_BYTE,
    MIXER_CTL_TYPE_IEC958,
    MIXER_CTL_TYPE_INT64,
    MIXER_CTL_TYPE_UNKNOWN,

    MIXER_CTL_TYPE_MAX,
};

struct mixer;

struct mixer_ctl {
    struct mixer *mixer;
    struct snd_ctl_elem_info *info;
    char **ename;
};

struct mixer {
    int fd;
    struct snd_ctl_card_info card_info;		//声卡信息
    struct snd_ctl_elem_info *elem_info;	//每一个控制项对应一个elem_info
    struct mixer_ctl *ctl;	//每一个控制项对应一个mixer_ctl
    unsigned int count;	//控制项个数
};

#define PCM_ERROR_MAX 128

struct pcm {
    int fd;					//文件描述符
    unsigned int flags;		//播放或者录音标志
    int running:1;			//pcm开始运行标志
    int underruns;			//PCM 流underruns计数
    unsigned int buffer_size;	//mmap buffer大小
    unsigned int boundary;		//????????????????????boundary表示什么
    char error[PCM_ERROR_MAX];	//pcm流错误
    struct pcm_config config;	//流配置参数
//    struct snd_pcm_mmap_status *mmap_status;
//    struct snd_pcm_mmap_control *mmap_control;
//    struct snd_pcm_sync_ptr *sync_ptr;
//    void *mmap_buffer;			//指向mmap buffer首地址
//    unsigned int noirq_frames_per_msec;
//    int wait_for_avail_min;
};

//#include "utils/log.h"

#define fn "/dev/snd/pcmC0D0p"

class SndPcmHWParam: private snd_pcm_hw_params {
private:
	static inline int is_mask(int p) {
		return (p >= SNDRV_PCM_HW_PARAM_FIRST_MASK) &&
			(p <= SNDRV_PCM_HW_PARAM_LAST_MASK);
	}

	static inline int is_interval(int p)	{
		return (p >= SNDRV_PCM_HW_PARAM_FIRST_INTERVAL) &&
			(p <= SNDRV_PCM_HW_PARAM_LAST_INTERVAL);
	}

public:
	inline snd_interval *to_interval(int n)	{
		return &(intervals[n - SNDRV_PCM_HW_PARAM_FIRST_INTERVAL]);
	}

	inline snd_mask *to_mask(int n)	{
		return &(masks[n - SNDRV_PCM_HW_PARAM_FIRST_MASK]);
	}

	void set_mask(int n, unsigned int bit)	{
		if (bit >= SNDRV_MASK_MAX)
			return;
		if (is_mask(n)) {
			snd_mask *m = to_mask(n);
			m->bits[0] = 0;
			m->bits[1] = 0;
			m->bits[bit >> 5] |= (1 << (bit & 31));
		}
	}

	void set_min(int n, unsigned int val)	{
		if (is_interval(n)) {
			snd_interval *i = to_interval(n);
			i->min = val;
		}
	}

	unsigned int get_min(int n)	{
		if (is_interval(n)) {
			snd_interval *i = to_interval(n);
			return i->min;
		}
		return 0;
	}

	unsigned int get_max(int n)	{
		if (is_interval(n)) {
			snd_interval *i = to_interval(n);
			return i->max;
		}
		return 0;
	}

	void set_int(int n, unsigned int val)	{
		if (is_interval(n)) {
			snd_interval *i = to_interval(n);
			i->min = val;
			i->max = val;
			i->integer = 1;
		}
	}

	unsigned int get_int(int n)	{
		if (is_interval(n)) {
			snd_interval *i = to_interval(n);
			if (i->integer)
				return i->max;
		}
		return 0;
	}

	void init() {
		int n;

		for (n = SNDRV_PCM_HW_PARAM_FIRST_MASK;
			 n <= SNDRV_PCM_HW_PARAM_LAST_MASK; n++) {
				snd_mask *m = to_mask(n);
				m->bits[0] = ~0;
				m->bits[1] = ~0;
		}
		for (n = SNDRV_PCM_HW_PARAM_FIRST_INTERVAL;
			 n <= SNDRV_PCM_HW_PARAM_LAST_INTERVAL; n++) {
				snd_interval *i = to_interval(n);
				i->min = 0;
				i->max = ~0;
		}
		rmask = ~0U;
		cmask = 0;
		info = ~0U;
	}
};


class PCM : public pcm{
private:
	int oops(int e, const char *fmt, ...) {
	    va_list ap;
	    int sz;

	    va_start(ap, fmt);
	    vsnprintf(error, PCM_ERROR_MAX, fmt, ap);
	    va_end(ap);
	    sz = strlen(error);

	    if (errno)
	        snprintf(error + sz, PCM_ERROR_MAX - sz, ": %s", strerror(e));
	    return -1;
	}

public:
	PCM (int _flags, const pcm_config& _config) {
		fd = open(fn, O_RDWR);	//���豸�ļ�
		if (fd < 0) {
			oops(errno, "cannot open device '%s'", fn);
			return;
		}
		flags = _flags;
		running = 0;
		underruns = 0;
		error[0] = 0;
		config = _config;

		/*���pcm info*/
	    struct snd_pcm_info info;
		if (ioctl(fd, SNDRV_PCM_IOCTL_INFO, &info)) {
			oops(errno, "cannot get info");
			goto fail_close;
		}

		/*hw_params初始化*/
	    SndPcmHWParam param;
		memset(&param, 0, sizeof(param));
		param.init();
	    param.set_mask(SNDRV_PCM_HW_PARAM_FORMAT, SNDRV_PCM_FORMAT_S16_LE); // pcm_format_to_alsa(config.format));
	    param.set_mask(SNDRV_PCM_HW_PARAM_SUBFORMAT, SNDRV_PCM_SUBFORMAT_STD);
	    param.set_min(SNDRV_PCM_HW_PARAM_PERIOD_SIZE, config.period_size);
	    param.set_int(SNDRV_PCM_HW_PARAM_SAMPLE_BITS, 16);
	    param.set_int(SNDRV_PCM_HW_PARAM_FRAME_BITS, 16 * config.channels);
	    param.set_int(SNDRV_PCM_HW_PARAM_CHANNELS, config.channels);
	    param.set_int(SNDRV_PCM_HW_PARAM_PERIODS, config.period_count);
	    param.set_int(SNDRV_PCM_HW_PARAM_RATE, config.rate);
	    param.set_mask(SNDRV_PCM_HW_PARAM_ACCESS, SNDRV_PCM_ACCESS_RW_INTERLEAVED);

	    if (ioctl(fd, SNDRV_PCM_IOCTL_HW_PARAMS, &param)) {
	        oops(errno, "cannot set hw params");
	        goto fail_close;
	    }

	    /* get our refined hw_params */
		/*获得重新定义的hw_params参数，由于前面设置的参数硬件不一定支持，alsa会设置新的参数*/
	    config.period_size = param.get_int(SNDRV_PCM_HW_PARAM_PERIOD_SIZE);
	    config.period_count = param.get_int(SNDRV_PCM_HW_PARAM_PERIODS);
	    buffer_size = config.period_count * config.period_size;


		/*设置sw_sparams参数*/
	    struct snd_pcm_sw_params sparams;
	    memset(&sparams, 0, sizeof(sparams));
		/*使能tstamp,对于不支持时间戳的设备，这里需要关闭掉*/
	    sparams.tstamp_mode = SNDRV_PCM_TSTAMP_ENABLE;
	    sparams.period_step = 1;

		/*如果设置config->start_threshold为0*/
	    if (!config.start_threshold) {
	    	config.start_threshold = sparams.start_threshold =
	    		config.period_count * config.period_size / 2;
	    } else
	        sparams.start_threshold = config.start_threshold;

	    /* pick a high stop threshold - todo: does this need further tuning */
	    if (!config.stop_threshold) {
			config.stop_threshold = sparams.stop_threshold =
				config.period_count * config.period_size;
	    } else
	        sparams.stop_threshold = config.stop_threshold;

	    if (!config.avail_min) {
            config.avail_min = sparams.avail_min = 1;
	    } else
	        sparams.avail_min = config.avail_min;

	    sparams.xfer_align = config.period_size / 2; /* needed for old kernels */
	    sparams.silence_size = 0;
	    sparams.silence_threshold = config.silence_threshold;
	    boundary = sparams.boundary = buffer_size;

	    while (boundary * 2 <= INT_MAX - buffer_size)
			boundary *= 2;

	    if (ioctl(fd, SNDRV_PCM_IOCTL_SW_PARAMS, &sparams)) {
	        oops(errno, "cannot set sw params");
	        goto fail;
	    }

	    return;

	fail:
	fail_close:
		close(fd);	//关闭文件描述符
		fd = -1;	//文件描述符设置为无效值
	}

	int write(const void *data, unsigned int count)	{
	    struct snd_xferi x;

	    x.buf = (void*)data;	//指向传输的数据
	    x.frames = count / (config.channels * (16 / 8));	//传输的帧数

	    for (;;) {
	        if (!running) {
	            if (ioctl(fd, SNDRV_PCM_IOCTL_PREPARE))
	                return oops(errno, "cannot prepare channel");
	            if (ioctl(fd, SNDRV_PCM_IOCTL_WRITEI_FRAMES, &x))
	                return oops(errno, "cannot write initial data");
	            running = 1;
	            return 0;
	        }
	        if (ioctl(fd, SNDRV_PCM_IOCTL_WRITEI_FRAMES, &x)) {
	            running = 0;
	            if (errno == EPIPE) {
	                /* we failed to make our window -- try to restart if we are
	                 * allowed to do so.  Otherwise, simply allow the EPIPE error to
	                 * propagate up to the app level */
	                underruns++;
					/*如果设置了PCM_NORESTART,如果发生EPIPE错误，直接退出并返回-EPIPE；如果没有设置PCM_NORESTART
					，写入数据发生PCM_NORESTART错误，可以认为流传输结束，可以再次开始传输*/
	                continue;
	            }
	            return oops(errno, "cannot write stream data");
	        }
	        return 0;
	    }

	    return 0;
	}

	~PCM () {
	    if (fd >= 0)
	        close(fd);
	    running = 0;
	    buffer_size = 0;
	    fd = -1;
	}
};

class MixerCtl;
class Mixer;

class MixerAPI {
public:
	struct mixer *(*mixer_open)(unsigned int card);
	void (*mixer_close)(struct mixer *__mixer);
	/* Obtain mixer controls */
	unsigned int (*mixer_get_num_ctls)(struct mixer *__mixer);
	struct mixer_ctl *(*mixer_get_ctl)(struct mixer *__mixer, unsigned int id);
	struct mixer_ctl *(*mixer_get_ctl_by_name)(struct mixer *__mixer, const char *name);
	/* Get info about mixer controls */
	const char *(*mixer_ctl_get_name)(struct mixer_ctl *ctl);
	enum mixer_ctl_type (*mixer_ctl_get_type)(struct mixer_ctl *ctl);
	const char *(*mixer_ctl_get_type_string)(struct mixer_ctl *ctl);
	unsigned int (*mixer_ctl_get_num_values)(struct mixer_ctl *ctl);
	unsigned int (*mixer_ctl_get_num_enums)(struct mixer_ctl *ctl);
	const char *(*mixer_ctl_get_enum_string)(struct mixer_ctl *ctl, unsigned int enum_id);
	/* Set and get mixer controls */
	int (*mixer_ctl_get_percent)(struct mixer_ctl *ctl, unsigned int id);
	int (*mixer_ctl_set_percent)(struct mixer_ctl *ctl, unsigned int id, int percent);
	int (*mixer_ctl_get_value)(struct mixer_ctl *ctl, unsigned int id);
	int (*mixer_ctl_set_value)(struct mixer_ctl *ctl, unsigned int id, int value);
	int (*mixer_ctl_set_enum_by_string)(struct mixer_ctl *ctl, const char *string);
	/* Determe range of integer mixer controls */
	int (*mixer_ctl_get_range_min)(struct mixer_ctl *ctl);
	int (*mixer_ctl_get_range_max)(struct mixer_ctl *ctl);

	friend class MixerCtl;
	friend class Mixer;
public:
	MixerAPI () {
		void* dp = dlopen ("/lib/libeasyui.so", RTLD_LAZY);
		mixer_open = dlsym(dp, "mixer_open");
		mixer_close = dlsym(dp, "mixer_close");
		mixer_ctl_get_enum_string = dlsym(dp, "mixer_ctl_get_enum_string");
		mixer_ctl_get_name = dlsym(dp, "mixer_ctl_get_name");
		mixer_ctl_get_num_enums = dlsym(dp, "mixer_ctl_get_num_enums");
		mixer_ctl_get_num_values = dlsym(dp, "mixer_ctl_get_num_values");
		mixer_ctl_get_percent = dlsym(dp, "mixer_ctl_get_percent");
		mixer_ctl_get_range_max = dlsym(dp, "mixer_ctl_get_range_max");
		mixer_ctl_get_range_min = dlsym(dp, "mixer_ctl_get_range_min");
		mixer_ctl_get_type = dlsym(dp, "mixer_ctl_get_type");
		mixer_ctl_get_type_string = dlsym(dp, "mixer_ctl_get_type_string");
		mixer_ctl_get_value = dlsym(dp, "mixer_ctl_get_value");
		mixer_ctl_set_enum_by_string = dlsym(dp, "mixer_ctl_set_enum_by_string");
		mixer_ctl_set_percent = dlsym(dp, "mixer_ctl_set_percent");
		mixer_ctl_set_value = dlsym(dp, "mixer_ctl_set_value");
		mixer_get_ctl = dlsym(dp, "mixer_get_ctl");
		mixer_get_ctl_by_name = dlsym(dp, "mixer_get_ctl_by_name");
		mixer_get_num_ctls = dlsym(dp, "mixer_get_num_ctls");
	}
};

extern MixerAPI __mixer;

class MixerCtl {
	friend class Mixer;
private:
	mixer_ctl* ctl;

	MixerCtl(mixer_ctl* ctrl) : ctl(ctrl) {}
public:
	inline MixerCtl(): ctl(0){}

	inline const char* Name() {
		return __mixer.mixer_ctl_get_name(ctl);
	}

	inline mixer_ctl_type Type(){
		return __mixer.mixer_ctl_get_type(ctl);
	}

	inline const char* TypeString(){
		return __mixer.mixer_ctl_get_type_string(ctl);
	}

//	inline unsigned int NumValues(){
//		return __mixer.mixer_ctl_get_num_values(ctl);
//	}
//
//	inline unsigned int NumEnums() {
//		return __mixer.mixer_ctl_get_num_enums(ctl);
//	}

	inline int Percent() {
		return __mixer.mixer_ctl_get_percent(ctl, 0);
	}

	inline int Percent(int percent) {
		return __mixer.mixer_ctl_set_percent(ctl, 0, percent);
	}

	inline int Value(){
		return __mixer.mixer_ctl_get_value(ctl, 0);
	}

	inline int Value(int value) {
		return __mixer.mixer_ctl_set_value(ctl, 0, value);
	}

	inline const char* GetEnumString(unsigned int enum_id) {
		return __mixer.mixer_ctl_get_enum_string(ctl, enum_id);
	}

	inline int SetEnumString(const char* string) {
		return __mixer.mixer_ctl_set_enum_by_string(ctl, string);
	}

	inline int RangeMin() {
		return __mixer.mixer_ctl_get_range_min(ctl);
	}

	inline int RangeMax() {
		return __mixer.mixer_ctl_get_range_max(ctl);
	}
};

class Mixer {
private:
	struct mixer* mix;
public:
	inline Mixer() {
		mix = __mixer.mixer_open(0);
	}

	inline ~Mixer() {
		__mixer.mixer_close(mix);
	}

	inline unsigned int Count() {
		return __mixer.mixer_get_num_ctls(mix);
	}

	inline MixerCtl operator [] (unsigned int id) {
		MixerCtl ctl(__mixer.mixer_get_ctl(mix, id));
		return ctl;
	}

	inline MixerCtl operator [] (const char *name) {
		MixerCtl ctl(__mixer.mixer_get_ctl_by_name(mix, name));
		return ctl;
	}

	int CtlValue(int id) {
		mixer_ctl* ctl = __mixer.mixer_get_ctl(mix, id);
		return __mixer.mixer_ctl_get_value(ctl, 0);
	}

	void CtlValue(int id, int value) {
		mixer_ctl* ctl = __mixer.mixer_get_ctl(mix, id);
		__mixer.mixer_ctl_set_value(ctl, 0, value);
	}

	void OpenSound() {
		CtlValue(1, 1);			// 右声道开启
		CtlValue(2, 1);			// 左声道开启
		CtlValue(22, 63);		// 主音量
	}

	void CloseSound() {
		CtlValue(1, 0);			// 右声道关闭
		CtlValue(2, 0);			// 左声道关闭
		CtlValue(22, 0);
	}
};

#if false
	// 列出声卡的所有信息
	MixerAPI __mixer;			// 这个必须要，否则无法动态链接的

	static bool onButtonClick_RStart(ZKButton *pButton) {
		Mixer mix;

		LOGD("Counts: %d", mix.Count());

		for(int i = 0; i < mix.Count(); i++) {
			MixerCtl ctl = mix[i];
			LOGD("%d    %s    %s    %d", i, ctl.Name(), ctl.TypeString(), ctl.Value());
		}
	}
#endif

#endif /* JNI_ACTIVITY_PCM_HPP_ */
