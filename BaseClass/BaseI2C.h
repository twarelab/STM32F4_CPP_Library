/*
 * BaseI2C.h
 *
 *  Created on: Apr 8, 2022
 *      Author: jameskim
 */

#ifndef TWARELABLIB_BASEI2C_H_
#define TWARELABLIB_BASEI2C_H_

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_i2c.h>
#include <twarelabType.h>

#ifdef __STM32F4xx_HAL_I2C_H

class BaseI2C {
protected:
	I2C_HandleTypeDef * hi2c;
	BOOL bIWDGEnable;
	IWDG_HandleTypeDef hiwdg;

public:
	BaseI2C();
	BaseI2C(I2C_HandleTypeDef * hi2c);
	virtual ~BaseI2C();

	void setIWDGEnable(BOOL flag);
	BOOL getIWDGEnable(void);
	void setIWDGHandler(IWDG_HandleTypeDef hIWDG);

	HAL_StatusTypeDef ReadMem(uint16_t DevAddr, uint16_t MemAddr, uint16_t MemAddSize, uint8_t * pData, uint16_t size);
	HAL_StatusTypeDef WriteMem(uint16_t DevAddr, uint16_t MemAddr, uint16_t MemAddSize, uint8_t * pData, uint16_t size);

};

#endif

#endif /* TWARELABLIB_BASEI2C_H_ */
