/*
 * ConsoleTask.h
 *
 *  Created on: Mar 26, 2022
 *      Author: jameskim
 */

#ifndef TASKS_CONSOLETASK_H_
#define TASKS_CONSOLETASK_H_

#include <BaseTask.h>

#include <twarelabType.h>

#include <BaseUART.h>

//#if defined(_CONSOLETASK_ENABLE_)
class ConsoleTask: public BaseTask {
public:
	BaseUART uart;
public:
	ConsoleTask();
	ConsoleTask(USART_TypeDef * uart, DMA_TypeDef * dmaport, uint32_t dmastream);
	ConsoleTask(USART_TypeDef * uart, DMA_TypeDef * txdmaport, uint32_t txdmastream, DMA_TypeDef * rxdmaport, uint32_t rxdmastream);
	virtual ~ConsoleTask();

	void run(void);
	void PRINTF(char *format, ...);

	BaseUART * getUARTHandler(void);

	void setUartTxEnabled(BOOL flag);
	void setUartRxEnabled(BOOL flag);

	void putTxBuf(uint8_t data);

	void flushTxBuf(void);

	void PrintBuf(uint8_t * buf, uint16_t size);
};
//#endif

#endif /* TASKS_CONSOLETASK_H_ */
