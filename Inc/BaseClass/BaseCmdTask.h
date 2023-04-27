/*
 * BaseCmdTask.h
 *
 *  Created on: Aug 9, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_BASECLASS_BASECMDTASK_H_
#define TWLABCPPLIB_BASECLASS_BASECMDTASK_H_

#include <BaseTask.h>

#include <twarelabType.h>
#include <BaseQueue.h>

#include <BaseUART.h>
#include <ConsoleTask.h>

#define IS_AF(c)		((c >= 'A') && (c <= 'F'))
#define IS_af(c)		((c >= 'a') && (c <= 'f'))
#define IS_09(c)		((c >= '0') && (c <= '9'))
#define ISVALIDHEX(c) IS_AF(c) || IS_af(c) || IS_09(c)

class BaseCmdTask: public BaseTask {
protected:

	ConsoleTask * CTask;

public:
//	BaseQueue RxBuf;
	BaseUART * CmdUart;
public:
	BaseCmdTask();

	BaseCmdTask(BaseUART * pUart, ConsoleTask * pTask);

	virtual ~BaseCmdTask();

//	void InitUart(USART_TypeDef * huart, DMA_TypeDef * dmaport, uint32_t dmastream);
//
//	void setCmdUartDMARxRcvd(BOOL flag);
//	BOOL getCmdUartDMARxRcvd(void);
//	void setCmdUartDMATxEnabled(BOOL flag);
//	BOOL getCmdUartDMATxEnabled(void);
//	void CmdUartDMAIDLECountIncrement(void);
//
//	uint8_t * getDMARxBufPtr(void);
//	void printDMARxBuf(void);
//	void CmdPortDMARxEnable(DMA_TypeDef * dmaport, uint32_t dmastream);
//
//	BaseQueue * getATCmdQueuePtr(void);

	unsigned char charToHexDigit(char c);
	unsigned char ascii2HexToByte(char c1, char c2);

	BOOL isValidIPAddr(uint8_t * IPAddr);
	BOOL isDigitString(char * str);
	uint8_t StringToInteger(char * str);

	void run(void);
};

#endif /* TWLABCPPLIB_BASECLASS_BASECMDTASK_H_ */
