/*
 * ProtocolParser.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: guoxs
 */
#include <vector>
#include <system/Mutex.h>
#include "CommDef.h"
#include "uart/ProtocolParser.h"
#include "utils/Log.h"
#include <algorithm>
#include <string>
static Mutex sLock;
static std::vector<OnProtocolDataUpdateFun> sProtocolDataUpdateListenerList;

void registerProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);
	LOGD("registerProtocolDataUpdateListener\n");
	if (pListener != NULL) {
		sProtocolDataUpdateListenerList.push_back(pListener);
	}
}

void unregisterProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);
	LOGD("unregisterProtocolDataUpdateListener\n");
	if (pListener != NULL) {
		std::vector<OnProtocolDataUpdateFun>::iterator iter = sProtocolDataUpdateListenerList.begin();
		for (; iter != sProtocolDataUpdateListenerList.end(); iter++) {
			if ((*iter) == pListener) {
				sProtocolDataUpdateListenerList.erase(iter);
				return;
			}
		}
	}
}

static void notifyProtocolDataUpdate(const SProtocolData &data) {
	Mutex::Autolock _l(sLock);
	std::vector<OnProtocolDataUpdateFun>::const_iterator iter = sProtocolDataUpdateListenerList.begin();
	for (; iter != sProtocolDataUpdateListenerList.end(); iter++) {
		(*iter)(data);
	}
}

static SProtocolData sProtocolData = { 0 };

SProtocolData& getProtocolData() {
	return sProtocolData;
}

/**
 * 获取校验码
 */
BYTE getCheckSum(const BYTE *pData, int len) {
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += pData[i];
	}

	return (BYTE) (~sum + 1);
}

/**
 * 解析每一帧数据
 */
static void procParse(const char *pData, UINT len) {




	sProtocolData.length = len;
	sProtocolData.str = pData;




	// 通知协议数据更新
	notifyProtocolDataUpdate(sProtocolData);
}

/**
 * 功能：解析协议
 * 参数：pData 协议数据，len 数据长度
 * 返回值：实际解析协议的长度
 */
int parseProtocol(const BYTE *pData, UINT len) {
	char dat[len + 1] = {0};
	strncpy(dat, (const char*)pData, len);//将串口接收到的数据储存到dat中
	procParse(dat, len);					// 啥都不处理，由串口事件自己处理

	return len;
}

//	if(len < DATA_PACKAGE_MIN_LEN)
//			return 0;
//
//	char dat[len + 1] = {0};
//		strncpy(dat, (const char*)pData, len);//将串口接收到的数据储存到dat中
//		char* ok = strstr(dat, "ok");     //检测dat是否含有ok
//		char* oX = strstr(dat, "@");
//		if(ok == NULL){                  //如果没有ok
//			if(dat[len - 1] == 'o')       //检测字符串末尾是否为o
//				len --;					  // 如果某位为o，则末尾的o不处理
//			procParse(dat, len);		  // 没有检测到ok发送到串口处理事件
//			return len;					  // 末尾如果含有o，等待下次拼接
//		}
//		else {                            //如果dat中含有ok
//			int lenOld = (int)ok - (int)dat;	// 查找ok出现的位置
//		    if(lenOld > 0)			  // 如果ok不是出现在开始
//		    	procParse(dat, len);	  // 串口处理ok前面的内容
//		    if(oX == NULL)
//                procParse("ok", 2); // 串口处理ok
//            if(oX !=NULL)
//		    	procParse(dat, len);	  // 串口处理ok前面的内容
//
//				return len; // ok后面的内容等待下次拼接
//			}
//		}
//
