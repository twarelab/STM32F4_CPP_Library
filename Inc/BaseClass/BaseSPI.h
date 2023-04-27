/*
 * BaseSPI.h
 *
 *  Created on: Apr 15, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_BASECLASS_BASESPI_H_
#define TWLABCPPLIB_BASECLASS_BASESPI_H_

#include <BaseGPIO.h>
#include <stm32f4xx_ll_rcc.h>
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_dma.h"

class BaseSPI {
public:
	SPI_TypeDef * pSPI;

	DMA_TypeDef * pTxDMAPort;
	DMA_TypeDef * pRxDMAPort;
	uint32_t TxDMAStream;
	uint32_t RxDMAStream;

	BaseGPIO nCS;
public:
	BaseSPI();
	BaseSPI(GPIO_TypeDef* port, uint32_t pin);
	BaseSPI(GPIOPIN gpiopin);
	virtual ~BaseSPI();

	void setSPIHandle(SPI_TypeDef * pSPI);
	void setTxDMAPort(DMA_TypeDef * pDMAPort);
	void setRxDMAPort(DMA_TypeDef * pDMAPort);
	void setTxDMAStream(uint32_t DMAStream);
	void setRxDMAStream(uint32_t DMAStream);

	void csEnable(void);
	void csDisable(void);
	void WriteByte(uint8_t data);
	uint8_t ReadByte(void);
	void WriteBurst(uint8_t * pBuf, uint16_t len);
	void ReadBurst(uint8_t * pBuf, uint16_t len);
};


#endif /* TWLABCPPLIB_BASECLASS_BASESPI_H_ */
