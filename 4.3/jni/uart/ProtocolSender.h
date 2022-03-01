/*
 * ProtocolSender.h
 *
 *  Created on: Sep 8, 2017
 *      Author: guoxs
 */

#ifndef _UART_PROTOCOL_SENDER_H_
#define _UART_PROTOCOL_SENDER_H_

#include "CommDef.h"

bool sendProtocol(const UINT16 cmdID,const BYTE *pData, BYTE len);

#endif /* _UART_PROTOCOL_SENDER_H_ */
