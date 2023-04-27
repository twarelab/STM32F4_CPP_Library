/*
 * BpUART.h
 *
 *  Created on: Apr 12, 2022
 *      Author: jameskim
 */

#ifndef TWARELABLIB_BPUART_H_
#define TWARELABLIB_BPUART_H_

//#if defined(__STM32F4xx_LL_USART_H) && defined(__STM32F4xx_LL_DMA_H) && defined(TASKS_STATUSLEDTASK_H_)

#include <BaseUART.h>
#include <BaseGPIO.h>
#include <ConsoleTask.h>

class BpUART: public BaseUART {
protected:
	BaseTimer * pBypassTimer;

	BpUART * pBypassUART;
	BOOL bBypass;

	BOOL bRepeat;
	uint8_t RepeatCount;
	uint16_t RepeatInterval;

	uint8_t CurrentRepeatCount;

	BaseTimer txretrytimer;
	ConsoleTask *CTask;

	uint8_t portIndex;

	string name;

	uint32_t BypassRxCount;
	uint32_t BypassTxCount;

	BOOL bIDLEoccur;

//	BaseGPIO rts;
//	BaseGPIO cts;
	BaseGPIO * rxled;
	BaseGPIO * txled;


public:
	BpUART();
	BpUART(string name, ConsoleTask * pTask);
	BpUART(USART_TypeDef * uart, DMA_TypeDef * dmaport, uint32_t dmastream, GPIOINFO * pGpio, ConsoleTask * pCTask, string name);
	BpUART(USART_TypeDef * uart, DMA_TypeDef * txdmaport, uint32_t txdmastream, DMA_TypeDef * rxdmaport, uint32_t rxdmastream, ConsoleTask * pCTask, string name);
	virtual ~BpUART();

//	void setRxLEDPin(GPIO_TypeDef* port, uint32_t pin);
//	void setTxLEDPin(GPIO_TypeDef* port, uint32_t pin);

	void setRxLEDPin(BaseGPIO * Gpio);
	void setTxLEDPin(BaseGPIO * Gpio);

	string getName(void);

	void setTXEnabled(BOOL flag);

//	BaseTimer * getRTSTimerHandle();
//	BaseTimer * getTXLEDTimerHandle();
//	BaseTimer * getRXLEDTimerHandle();
//
//	BaseGPIO * getRTSHandle();
//	BaseGPIO * getCTSHandle();
//	BaseGPIO * getTXLEDHandle();
//	BaseGPIO * getRXLEDHandle();

	void printRxBufInfo();
//	void DMARxEnable(DMA_TypeDef * dmaport, uint32_t dmastream);
	void setBypassTimer(BaseTimer * pTimer);

	void setBypassUART(BpUART* pBpUart);
	void setBypass(BOOL flag);
	BOOL getBypass(void);

	void setBypassTxCount(uint32_t val);
	uint32_t getBypassTxCount(void);
	void setBypassRxCount(uint32_t val);
	uint32_t getBypassRxCount(void);
	void increaseBypassTxCount(void);
	void increaseBypassRxCount(void);

	void setIdleTimerActivate(void);
	void setIdleTimerCount(uint16_t count);
	void moveDMABufToRXQueue(void);
	void moveToBPUartTxQueue(void);

	void setRepeatFlag(BOOL flag);
	void setRepeatCount(uint8_t count);
	void setRepeatInterval(uint16_t interval);

	void setIDLEFlag(BOOL flag);
	BOOL getIDLEFlag(void);

	BaseTimer * getTxRetryTimerPtr(void);

	void UARTReInit(USART_TypeDef * uart, BAUDRATE baudrate);
	void UARTReInit(USART_TypeDef * uart, BAUDRATE baudrate, PARITY parity);

	void TxProcess(void);
	void RxProcess(void);

	void run(void);
};

#endif /* TWARELABLIB_BPUART_H_ */
