/*
 * ProtocolData.h
 *
 *  Created on: Sep 7, 2017
 *      Author: guoxs
 */

#ifndef _UART_PROTOCOL_DATA_H_
#define _UART_PROTOCOL_DATA_H_

#include <string>
#include "CommDef.h"

/******************** CmdID ***********************/
// #define CMDID_POWER							0x0
/**************************************************/

/******************** 错误码 ***********************/
// #define ERROR_CODE_CMDID			1
/**************************************************/

typedef struct {
	const char* str;
	int length;
	const char*  T0;
	const char*  T1;
	const char*  T2;
	const char*  T3;
	const char*  T4;
	const char*  B0;
} SProtocolData;

#endif /* _UART_PROTOCOL_DATA_H_ */
