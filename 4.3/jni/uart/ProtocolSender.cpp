/*
 * ProtocolSender.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: guoxs
 */

#include "uart/ProtocolSender.h"
#include "uart/UartContext.h"
#include <stdio.h>

extern BYTE getCheckSum(const BYTE *pData, int len);

/**
 * 需要根据协议格式进行拼接，以下只是个模板
 */
bool sendProtocol(const UINT16 cmdID, const BYTE *pData, BYTE len) {
	BYTE dataBuf[256];

	dataBuf[0] = CMD_HEAD1;
	dataBuf[1] = CMD_HEAD2;			// 同步帧头

	dataBuf[2] = HIBYTE(cmdID);
	dataBuf[3] = LOBYTE(cmdID);		// 命令字节

	dataBuf[4] = len;

	UINT frameLen = 5;

	// 数据
	for (int i = 0; i < len; ++i) {
		dataBuf[frameLen] = pData[i];
		frameLen++;
	}

#ifdef PRO_SUPPORT_CHECK_SUM
	// 校验码
	dataBuf[frameLen] = getCheckSum(dataBuf, frameLen);
	frameLen++;
#endif

	return UARTCONTEXT->send(dataBuf, frameLen);
}
