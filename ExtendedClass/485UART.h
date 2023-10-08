/*
 * 485UART.h
 *
 *  Created on: 2023. 9. 22.
 *      Author: james
 */

#ifndef EXTENDEDCLASS_485UART_H_
#define EXTENDEDCLASS_485UART_H_

#include <BaseUART.h>
#include <BaseGPIO.h>

class _485UART: public BaseUART {
public:
	BaseGPIO * TxEnablePin;
public:
	_485UART();
	_485UART(USART_TypeDef * uart, DMA_TypeDef * txdmaport, uint32_t txdmastream, DMA_TypeDef * rxdmaport, uint32_t rxdmastream);
	virtual ~_485UART();

	void setTxEnablePinPtr(BaseGPIO * pin);

	void IDLEInterruptHandler(void);

	void TxProcess(void);

	void run(void);

};

#endif /* EXTENDEDCLASS_485UART_H_ */
