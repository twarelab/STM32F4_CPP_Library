/*
 * STM32UBoot.h
 *
 *  Created on: Dec 8, 2022
 *      Author: jameskim
 */

#ifndef UBOOT_STM32UBOOT_H_
#define UBOOT_STM32UBOOT_H_

#include <ConsoleTask.h>
#include <BaseUART.h>

typedef enum{
	CMD_BOOTENTER			= 0x7F,
	CMD_GETCODE				= 0x00,
	CMD_GETVER				= 0x01,
	CMD_GETID				= 0x02,
	CMD_READMEM				= 0x11,
	CMD_GO					= 0x21,
	CMD_WRITEMEM			= 0x31,
	CMD_ERASE				= 0x43,
	CMD_EXTRAERASE			= 0x44,
	CMD_WRITEPROTECT		= 0x63,
	CMD_WRITEUNPROTECT		= 0x73,
	CMD_READPROTECT			= 0x82,
	CMD_READUNPROTECT		= 0x92,
	CMD_GETCHECKSUM			= 0xA1
}STM32BOOTCMD;

typedef enum{
	RPY_ACK					= 0x79,
	RPY_NAK					= 0x1F,
	RPY_UNKNOWN				= 0xFF,
	RPY_NONE				= 0x00
}STM32BOOTRPY;

typedef enum{
	SSTATE_IDLE					= 0,
	SSTATE_SENT_CMD				= 1,
	SSTATE_RCVD_1stACK			= 2,
	SSTATE_RCVD_2ndACK			= 3,
	SSTATE_RCVD_3rdACK			= 4,
	SSTATE_RCVD_4thACK			= 5,
	SSTATE_RCVD_5thACK			= 6,
	SSTATE_RCVD_6thACK			= 7,
	SSTATE_RCVD_7thACK			= 8,
	SSTATE_RCVD_NUMOFBYTE		= 9,
	SSTATE_RCVD_DATA			= 10,
	SSTATE_SENT_ADDR			= 11,
	SSTATE_SENT_NUMOFBYTE		= 12,
	SSTATE_SENT_GLOBALERASE		= 13,
	SSTATE_SENT_NOBANDDATA		= 14,
	SSTATE_SENT_WORDLENGTH		= 15,
	SSTATE_SENT_CRCPOLY			= 16,
	SSTATE_SENT_CRCINIT			= 17,
	SSTATE_PREPARED				= 18,
	SSTATE_SUCCESS				= 55,
	SSTATE_FAIL					= 66,
}STM32BOOTSUBSTATE;

typedef enum{
	MSTATE_IDLE					= 0,
	MSTATE_BOOTENTER			= 1,
	MSTATE_GETCODE				= 2,
	MSTATE_GETVERSION			= 3,
	MSTATE_GETID				= 4,
	MSTATE_RDPCHECK				= 5,
	MSTATE_READUNPROTECT		= 6,
	MSTATE_READPROTECT			= 7,
	MSTATE_WRITECODE_1			= 8,
	MSTATE_WRITECODE_2			= 9,
	MSTATE_WRITECODE_3			= 10,
	MSTATE_ERASE				= 11,
	MSTATE_EXTRAERASE			= 12,
	MSTATE_GETCHECKSUM			= 13,
	MSTATE_WRITEPROTECT			= 14,
	MSTATE_WRITEUNPROTECT		= 15,
	MSTATE_GO					= 16,
	MSTATE_READMEM				= 17,
	MSTATE_WRITEMEM				= 18,
	MSTATE_READFLASH			= 19,
	MSTATE_WAITTIMEOUT			= 20,
	MSTATE_SUCCESS				= 55,
	MSTATE_FAIL					= 66
}STM32BOOTMAINSTATE;

#define MAX_TXBUF_LEN	(256 + 10)

typedef struct _RXDATASTRUCT_{
	uint16_t bytenum;
	uint16_t rcvdptr;
	uint8_t databuf[256 + 1];
}RXDATASTRUCT;

class STM32UBoot {
protected:
	ConsoleTask * CTask;
	uint8_t buf[MAX_TXBUF_LEN];
	uint16_t buflen;
	RXDATASTRUCT RxData;
	uint8_t dataBuf[256];
	uint32_t CRCPoly;
	uint32_t CRCInit;
public:
	BaseUART * pUart;
	uint8_t MainState;
	uint8_t SubState;
	uint32_t StartAddr;
	uint32_t Length;

public:
	STM32UBoot();
	STM32UBoot(BaseUART * pUart, ConsoleTask * pTask);
	virtual ~STM32UBoot();

	void appendCheckSum();
	void makeTxMsg(uint8_t opcode);
	void printBuf(string bufname, uint8_t * buf, uint16_t len);

	void sendCmd(STM32BOOTCMD cmd, BOOL bAppendChecksum, string cmdStr);

	void checkACK(STM32BOOTSUBSTATE nextState);
	void changetoSuccess(BOOL bRcvdData);

	void setStartAddr(uint32_t addr);
	void setLength(uint32_t len);
	void setCRCPoly(uint32_t crcpoly);
	void setCRCInit(uint32_t crcinit);

	uint8_t * getDataBufPtr(void);

	void putTxBuf(string cmdStr);

	BOOL checkRxDataAllFF(void);

	void processBootEnter(void);
	void processGetCode(void);
	void processGetVersion(void);
	void processGetID(void);
	void processReadMem(void);
	void processGo(void);
	void processWriteMem(void);
	void processErase(void);
	void processExtraErase(void);
	void processWriteProtect(void);
	void processWriteUnprotect(void);
	void processReadProtect(void);
	void processReadUnprotect(void);
	void processGetChecksum(void);
};

#endif /* UBOOT_STM32UBOOT_H_ */
