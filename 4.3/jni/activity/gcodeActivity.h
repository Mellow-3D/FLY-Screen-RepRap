/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __GCODEACTIVITY_H__
#define __GCODEACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_GCODE_Y_Value    50026
#define ID_GCODE_X_Value    50025
#define ID_GCODE_X_axis_maximum    91010
#define ID_GCODE_Y_axis_maximum    91009
#define ID_GCODE_coordinate    50021
#define ID_GCODE_Move_XY    20061
#define ID_GCODE_Message_Report_Close    20057
#define ID_GCODE_Message_Report    50020
#define ID_GCODE_home    110003
#define ID_GCODE_SubItem2    24002
#define ID_GCODE_moreseticon    24001
#define ID_GCODE_TextView62    50019
#define ID_GCODE_Button50    20059
#define ID_GCODE_Button51    20058
#define ID_GCODE_TextView61    50018
#define ID_GCODE_Button49    20056
#define ID_GCODE_Button47    20055
#define ID_GCODE_TextView60    50017
#define ID_GCODE_Button46    20054
#define ID_GCODE_Button12    20053
#define ID_GCODE_Button30    20046
#define ID_GCODE_Button29    20021
#define ID_GCODE_Button19    20009
#define ID_GCODE_Button40    20007
#define ID_GCODE_Button45    20052
#define ID_GCODE_Button44    20050
#define ID_GCODE_Button43    20048
#define ID_GCODE_Button42    20047
#define ID_GCODE_TextView59    50014
#define ID_GCODE_Button59    20004
#define ID_GCODE_Button36    20003
#define ID_GCODE_Button38    20045
#define ID_GCODE_Button37    20044
#define ID_GCODE_file_icon    20041
#define ID_GCODE_Anti_touch    110006
#define ID_GCODE_Textview38    50040
#define ID_GCODE_Textview26    50028
#define ID_GCODE_Textview21    50023
#define ID_GCODE_czzx    110005
#define ID_GCODE_Textview50    50052
#define ID_GCODE_Edittext3    51003
#define ID_GCODE_lock    110011
#define ID_GCODE_Button96    20105
#define ID_GCODE_TextView22    50079
#define ID_GCODE_Button84    20093
#define ID_GCODE_Button85    20094
#define ID_GCODE_Button86    20095
#define ID_GCODE_Button87    20096
#define ID_GCODE_Button88    20097
#define ID_GCODE_Button89    20098
#define ID_GCODE_Button90    20099
#define ID_GCODE_Button91    20100
#define ID_GCODE_Button92    20101
#define ID_GCODE_Button93    20102
#define ID_GCODE_Button94    20103
#define ID_GCODE_Button95    20104
#define ID_GCODE_TextView18    50030
#define ID_GCODE_AJ    110022
#define ID_GCODE_Button168    20177
#define ID_GCODE_Button167    20176
#define ID_GCODE_Button166    20175
#define ID_GCODE_Button165    20174
#define ID_GCODE_Button164    20173
#define ID_GCODE_Button163    20172
#define ID_GCODE_Button162    20171
#define ID_GCODE_Button161    20170
#define ID_GCODE_Button160    20169
#define ID_GCODE_Button159    20168
#define ID_GCODE_Button158    20167
#define ID_GCODE_Button157    20166
#define ID_GCODE_Button156    20165
#define ID_GCODE_Button155    20164
#define ID_GCODE_Button154    20163
#define ID_GCODE_Button153    20162
#define ID_GCODE_Button152    20161
#define ID_GCODE_Button151    20160
#define ID_GCODE_Button150    20159
#define ID_GCODE_Button149    20158
#define ID_GCODE_Button148    20157
#define ID_GCODE_Button147    20156
#define ID_GCODE_Button146    20155
#define ID_GCODE_Button145    20154
#define ID_GCODE_Button144    20153
#define ID_GCODE_Button143    20152
#define ID_GCODE_Button142    20151
#define ID_GCODE_Button141    20150
#define ID_GCODE_Button140    20149
#define ID_GCODE_Button139    20148
#define ID_GCODE_Button138    20147
#define ID_GCODE_Button137    20146
#define ID_GCODE_Button136    20145
#define ID_GCODE_Button135    20144
#define ID_GCODE_Button134    20143
#define ID_GCODE_Button133    20142
#define ID_GCODE_Button132    20141
#define ID_GCODE_Button131    20140
#define ID_GCODE_Button130    20139
#define ID_GCODE_Button129    20138
#define ID_GCODE_Button127    20137
#define ID_GCODE_Button126    20135
#define ID_GCODE_Button125    20134
#define ID_GCODE_TextView44    50101
#define ID_GCODE_TextView46    50103
#define ID_GCODE_AJ1    110027
#define ID_GCODE_Button108    20117
#define ID_GCODE_Button107    20116
#define ID_GCODE_Button106    20115
#define ID_GCODE_TextView43    50100
#define ID_GCODE_Edittext4    51004
#define ID_GCODE_Textview60    50062
#define ID_GCODE_TextView56    50013
#define ID_GCODE_TextView54    50012
#define ID_GCODE_QRCode1    92001
#define ID_GCODE_TextView14    50009
#define ID_GCODE_TextView2    50011
#define ID_GCODE_Button31    20028
#define ID_GCODE_moretime    80004
#define ID_GCODE_Textview54    50057
#define ID_GCODE_Textview51    50056
#define ID_GCODE_Seekbar3    91003
#define ID_GCODE_Button48    20060
#define ID_GCODE_Edittext2    51002
#define ID_GCODE_Textview53    50055
#define ID_GCODE_srecc    80003
#define ID_GCODE_morepmset    110010
#define ID_GCODE_ListView2    80007
#define ID_GCODE_Button109    20118
#define ID_GCODE_TextView45    50102
#define ID_GCODE_ListView1    80006
#define ID_GCODE_morehml    110026
#define ID_GCODE_ListView5    80010
#define ID_GCODE_ListView4    80009
#define ID_GCODE_ListView3    80008
#define ID_GCODE_moregj    110012
#define ID_GCODE_Button17    20026
#define ID_GCODE_Button16    20025
#define ID_GCODE_Button15    20024
#define ID_GCODE_Button14    20023
#define ID_GCODE_Button13    20022
#define ID_GCODE_TextView55    50010
#define ID_GCODE_EditText2    51007
#define ID_GCODE_EditText1    51006
#define ID_GCODE_wifi    110032
#define ID_GCODE_more    110020
#define ID_GCODE_Button100    20109
#define ID_GCODE_Button99    20108
#define ID_GCODE_Button98    20107
#define ID_GCODE_Button97    20106
#define ID_GCODE_TextView37    50094
#define ID_GCODE_Button128    20136
#define ID_GCODE_Button124    20133
#define ID_GCODE_Button123    20132
#define ID_GCODE_Button122    20131
#define ID_GCODE_Button121    20130
#define ID_GCODE_Button120    20129
#define ID_GCODE_Button119    20128
#define ID_GCODE_Button118    20127
#define ID_GCODE_Button117    20126
#define ID_GCODE_Button116    20125
#define ID_GCODE_Button115    20124
#define ID_GCODE_Button114    20123
#define ID_GCODE_Button113    20122
#define ID_GCODE_Button112    20121
#define ID_GCODE_Button111    20120
#define ID_GCODE_Button110    20119
#define ID_GCODE_whcs    110025
#define ID_GCODE_Button18    20027
#define ID_GCODE_whtp    110024
#define ID_GCODE_TextView42    50099
#define ID_GCODE_TextView41    50098
#define ID_GCODE_TextView40    50097
#define ID_GCODE_Button105    20114
#define ID_GCODE_Button104    20113
#define ID_GCODE_TextView39    50096
#define ID_GCODE_Button103    20112
#define ID_GCODE_Button102    20111
#define ID_GCODE_Button101    20110
#define ID_GCODE_Textview63    50065
#define ID_GCODE_Button39    20049
#define ID_GCODE_Button33    20043
#define ID_GCODE_Button32    20042
#define ID_GCODE_TextView38    50095
#define ID_GCODE_whcl    110007
#define ID_GCODE_TextView36    50093
#define ID_GCODE_TextView35    50092
#define ID_GCODE_TextView34    50091
#define ID_GCODE_SeekBar4    91008
#define ID_GCODE_Button22    20031
#define ID_GCODE_Button21    20030
#define ID_GCODE_Button24    20033
#define ID_GCODE_Button25    20034
#define ID_GCODE_Button1    20010
#define ID_GCODE_Button20    20029
#define ID_GCODE_TextView33    50090
#define ID_GCODE_TextView32    50089
#define ID_GCODE_TextView30    50087
#define ID_GCODE_SubItem1    20038
#define ID_GCODE_Listview1    80002
#define ID_GCODE_whmove    110023
#define ID_GCODE_WH    110019
#define ID_GCODE_Button79    20088
#define ID_GCODE_TextView58    50016
#define ID_GCODE_TextView57    50015
#define ID_GCODE_Button35    20040
#define ID_GCODE_SeekBar7    91001
#define ID_GCODE_Button34    20039
#define ID_GCODE_Button83    20092
#define ID_GCODE_Button82    20091
#define ID_GCODE_Button81    20090
#define ID_GCODE_Button80    20089
#define ID_GCODE_TextView31    50088
#define ID_GCODE_TextView29    50086
#define ID_GCODE_TextView28    50085
#define ID_GCODE_TextView27    50084
#define ID_GCODE_TextView25    50082
#define ID_GCODE_TextView24    50081
#define ID_GCODE_TextView23    50080
#define ID_GCODE_TextView21    50078
#define ID_GCODE_TextView20    50077
#define ID_GCODE_TextView19    50076
#define ID_GCODE_printcs    110021
#define ID_GCODE_TextView9    50074
#define ID_GCODE_TextView26    50083
#define ID_GCODE_TextView17    50075
#define ID_GCODE_TextView16    50035
#define ID_GCODE_TextView15    50034
#define ID_GCODE_TextView13    50031
#define ID_GCODE_TextView130    50033
#define ID_GCODE_TextView12    50029
#define ID_GCODE_Button78    20087
#define ID_GCODE_TextView11    50024
#define ID_GCODE_TextView10    50022
#define ID_GCODE_Seekbar4    91004
#define ID_GCODE_btnBack    20008
#define ID_GCODE_btnPause    20002
#define ID_GCODE_TextView53    50008
#define ID_GCODE_winPrint    110001
#define ID_GCODE_btnPrintCancel    20006
#define ID_GCODE_btnPrintOK    20005
#define ID_GCODE_df    50001
#define ID_GCODE_winQueryPrint    110002
#define ID_GCODE_Button11    20020
#define ID_GCODE_Button10    20019
#define ID_GCODE_Button9    20018
#define ID_GCODE_fish    110031
#define ID_GCODE_boardsd    80011
#define ID_GCODE_Icon    20001
#define ID_GCODE_LVFolder    80001
#define ID_GCODE_print    110018
#define ID_GCODE_Button75    20084
#define ID_GCODE_Button4    20013
#define ID_GCODE_TextView52    50007
#define ID_GCODE_TextView51    50006
#define ID_GCODE_TextView50    50005
#define ID_GCODE_Button8    20017
#define ID_GCODE_Button7    20016
#define ID_GCODE_Button6    20015
#define ID_GCODE_Button5    20014
#define ID_GCODE_TextView49    50004
#define ID_GCODE_TextView48    50003
#define ID_GCODE_temprc    110029
#define ID_GCODE_tempbx    120003
#define ID_GCODE_TextView6    50071
#define ID_GCODE_Button77    20086
#define ID_GCODE_TextView7    50072
#define ID_GCODE_TextView8    50073
#define ID_GCODE_Button3    20012
#define ID_GCODE_Button76    20085
#define ID_GCODE_Button2    20011
#define ID_GCODE_Button180    20189
#define ID_GCODE_TextView47    50041
#define ID_GCODE_TextView5    50064
#define ID_GCODE_Button178    20187
#define ID_GCODE_Button179    20188
#define ID_GCODE_TextView4    50069
#define ID_GCODE_temppt    110028
#define ID_GCODE_temp    110004
#define ID_GCODE_SeekBar3    91007
#define ID_GCODE_SeekBar2    91006
#define ID_GCODE_SeekBar1    91005
#define ID_GCODE_Button41    20051
#define ID_GCODE_Textview37    50039
#define ID_GCODE_Textview36    50038
#define ID_GCODE_Textview34    50036
#define ID_GCODE_Button28    20037
#define ID_GCODE_Button27    20036
#define ID_GCODE_Button26    20035
#define ID_GCODE_TextView1    50002
#define ID_GCODE_Button23    20032
#define ID_GCODE_Button70    20079
#define ID_GCODE_Button71    20080
#define ID_GCODE_Button72    20081
#define ID_GCODE_Button73    20082
#define ID_GCODE_Button74    20083
#define ID_GCODE_TextView3    50068
/*TAG:Macro宏ID END*/

class gcodeActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    gcodeActivity();
    virtual ~gcodeActivity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif