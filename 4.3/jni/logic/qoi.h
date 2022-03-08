/*
 * qoi.h
 *
 *  Created on: 2022年3月6日
 *      Author: Administrator
 */

#ifndef JNI_LOGIC_QOI_H_
#define JNI_LOGIC_QOI_H_

#include <string>
#include "control/ZKBase.h"

typedef struct {
	unsigned int width;
	unsigned int height;
	unsigned char channels;
	unsigned char colorspace;
} qoi_desc;

extern "C"
void *qoi_decode(const void *data, int size, qoi_desc *desc, int channels);

struct QOIUtils {

	static std::string base64_decode(const char* data, int len, int& outLen) {
		//解码表
		const char decodeTable[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,
				62, // '+'
				0, 0, 0,
				63, // '/'
				52, 53, 54, 55, 56, 57, 58, 59, 60,
				61, // '0'-'9'
				0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
				13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
				25, // 'A'-'Z'
				0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
				37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
		};

		//返回值
		std::string strDecode;
		int nValue;
		int i = 0;
		while (i < len) {
			if (*data != '\r' && *data != '\n') {
				nValue = decodeTable[*data++] << 18;
				nValue += decodeTable[*data++] << 12;
				strDecode += (nValue & 0x00FF0000) >> 16;
				outLen ++;
				if (*data != '=') {
					nValue += decodeTable[*data++] << 6;
					strDecode += (nValue & 0x0000FF00) >> 8;
					outLen++;
					if (*data != '=') {
						nValue += decodeTable[*data++];
						strDecode += nValue & 0x000000FF;
						outLen ++;
					}
				}
				i += 4;
			} else {				// 回车换行,跳过
				data ++;
				i++;
			}
		}
		return strDecode;
	}

	static void set_qoi_image(ZKBase* bs, const std::string& input) {
		int outlen;
		std::string buf = base64_decode(input.c_str(), input.length(), outlen);
		qoi_desc desc;
		void* qoibuf = qoi_decode(buf.c_str(), buf.length(), &desc, 4);

		int* bmp = (int*)calloc(10, sizeof(int));
		bmp[0] = 0x00042002;
		bmp[2] = desc.width;
		bmp[3] = desc.height;
		bmp[4] = desc.width * 4;
		bmp[5] = (int) qoibuf;

		bs->setBackgroundBmp((PBITMAP)bmp);
	}
};

#endif /* JNI_LOGIC_QOI_H_ */
