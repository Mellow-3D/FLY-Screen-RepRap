/*
 * CommDef.h
 *
 *  Created on: 2016-2-15
 *      Author: guoxs
 */

#ifndef _UART_COMMDEF_H_
#define _UART_COMMDEF_H_

#ifndef BYTE
typedef unsigned char	BYTE;
#endif
#ifndef UINT
typedef unsigned int	UINT;
#endif
#ifndef UINT16
typedef unsigned short  UINT16;
#endif

#ifndef MAKEWORD
#define MAKEWORD(low, high)		(((BYTE)(low)) | (((BYTE)(high)) << 8))
#endif

#ifndef LOBYTE
#define LOBYTE(l)           ((BYTE)(l))
#endif

#ifndef HIBYTE
#define HIBYTE(l)           ((BYTE)(l >> 8))
#endif

#ifndef TABLESIZE
#define TABLESIZE(table)    (sizeof(table)/sizeof(table[0]))
#endif


// 需要打印协议数据时，打开以下宏
//#define DEBUG_PRO_DATA

// 支持checksum校验，打开以下宏
//#define PRO_SUPPORT_CHECK_SUM


/* SynchFrame CmdID  DataLen Data CheckSum (可选) */
/*     2Byte  2Byte   1Byte	N Byte  1Byte */
// 有CheckSum情况下最小长度: 2 + 2 + 1 + 1 = 6
// 无CheckSum情况下最小长度: 2 + 2 + 1 = 5

#ifdef PRO_SUPPORT_CHECK_SUM
#define DATA_PACKAGE_MIN_LEN		6
#else
#define DATA_PACKAGE_MIN_LEN		2
#endif

// 同步帧头
#define CMD_HEAD1	'o'
#define CMD_HEAD2	'k'

#endif /* _UART_COMMDEF_H_ */
