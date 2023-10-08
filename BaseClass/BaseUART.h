/*
 * BaseUART.h
 *
 *  Created on: Mar 26, 2022
 *      Author: jameskim
 */

#ifndef TWARELABLIB_BASEUART_H_
#define TWARELABLIB_BASEUART_H_

#include "twarelabType.h"
#include <stm32f4xx_ll_rcc.h>
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_dma.h"
#include "BaseTimer.h"
#include <queue>

#include <BaseQueue.h>

#include <ConverterTask.h>

using namespace std;

#define DATABUF_SIZE	1024
#define MAX_QUEUE_SIZE	2048

#if defined(__STM32F4xx_LL_USART_H) && defined(__STM32F4xx_LL_DMA_H)
class BaseUART {
protected:
	USART_TypeDef * uart;
	DMA_TypeDef * tx_dmaport;
	DMA_TypeDef * rx_dmaport;
	uint32_t tx_dmastream;
	uint32_t rx_dmastream;

	BOOL bTXDataReady;
	BOOL bRXDataReady;
	BOOL bRXEnabled;

	BaseTimer reinittimer;
	BaseTimer idletimer;

	BaseQueue TxBuf;

	uint8_t dmaTxBuf[DMA_BUF_SIZE + 1];
	uint16_t dmaTxBufSize;

	BOOL bEnable;
	BAUDRATE baudrate;
	PARITY parity;
	FLOWCTRL flowctrl;

	ConverterTask Convert;
public:
	dma_buf DMARxBuf;
	BOOL bTXEnabled;
	BaseQueue RxBuf;

public:
	BaseUART();
	BaseUART(USART_TypeDef * uart, DMA_TypeDef * txdmaport, uint32_t txdmastream);
	BaseUART(USART_TypeDef * uart, DMA_TypeDef * txdmaport, uint32_t txdmastream, DMA_TypeDef * rxdmaport, uint32_t rxdmastream);

	virtual ~BaseUART();

	void setTXEnabled(BOOL flag);
	BOOL getTXEnabled(void);

	void setTXDataReady(BOOL flag);
	BOOL getTXDataReady(void);

	void setRXDataReady(BOOL flag);
	BOOL getRXDataReady(void);

	void setRXEnabled(BOOL flag);
	BOOL getRXEnabled(void);

	void setDMARcvd(BOOL flag);
	BOOL getDMARcvd(void);

	void setEnable(BOOL flag);
	BOOL getEnable(void);

	void setBaudRateIndex(BAUDRATE index);
	uint32_t getBaudRate(void);
	BAUDRATE getBaudRateIndex(void);
	void setParityIndex(PARITY index);
	uint32_t getParity(void);
	PARITY getParityIndex(void);
	void setFlowCtrlIndex(FLOWCTRL index);
	uint32_t getFlowCtrl(void);
	FLOWCTRL getFlowCtrlIndex(void);

	BOOL getIdleTimerEnable(void);
	void setIdleTimerEnable(BOOL flag);

	void putTXQueue(uint8_t data);
	uint8_t getTXQueue(void);
	uint16_t getTXQueueLen(void);
	void putRXQueue(uint8_t data);
	uint8_t getRXQueue(void);
	uint16_t getRXQueueLen(void);

	void printDMARxBuf(void);
	uint8_t * getDMARxBufPtr(void);

	void DMARxEnable(void);
	void DMARxEnable(DMA_TypeDef * dmaport, uint32_t dmastream);

	void TxBufClear(void);
	void RxBufClear(void);

	void ClearInterruptCounter(void);

	uint16_t getIDLECount(void);
	uint16_t getHTCount(void);
	uint16_t getTCCount(void);

	BOOL getIdleTimerTrigger(void);

	BaseTimer * getReinitTimerPtr(void);
	BaseTimer * getIdleTimerHandle();

	void IDLEInterruptHandler(void);
	void RXDMAInterruptHandler(void);
	void TXDMAInterruptHandler(void);

	USART_TypeDef * getUartHandle(void);

	uint16_t makeDMATxBuf(void);

	void setDMATXActivate(void);

	void UARTReInit(USART_TypeDef * uart, BAUDRATE baudrate);
	void UARTReInit(USART_TypeDef * uart, BAUDRATE baudrate, PARITY parity);

	void moveDMABufToRXQueue(void);
	void TxProcess(void);
	void RxProcess(void);

	void run(void);
};
#endif

#endif /* TWARELABLIB_BASEUART_H_ */
