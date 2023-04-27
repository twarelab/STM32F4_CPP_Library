/*
 * BaseGPIO.h
 *
 *  Created on: 2022. 2. 19.
 *      Author: james
 */

#ifndef TWARELABLIB_BASEGPIO_H_
#define TWARELABLIB_BASEGPIO_H_


//#if defined(_CONSOLETASK_ENABLE_)
#include <ConsoleTask.h>
//#endif

#include <twarelabType.h>
#include "stm32f4xx_ll_gpio.h"
#include "BaseTimer.h"
#include <queue>

using namespace std;

#ifdef __STM32F4xx_LL_GPIO_H

class BaseGPIO {
protected:
	BOOL enable;
	GPIODIRECTION direction;
	GPIO_VAL currentVal;

	queue<GPIOStruct> GQueue ;
	BaseTimer timer;
	BOOL bProcess;
//#if defined(_CONSOLETASK_ENABLE_)
	ConsoleTask * CTask;
//#endif
public:
	GPIO_TypeDef* port;
	uint32_t pin;

public:

	BaseGPIO();
	BaseGPIO(GPIO_TypeDef* port, uint32_t pin);
	BaseGPIO(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);
	BaseGPIO(GPIOPIN gpiopin);
	BaseGPIO(GPIOINFO gpioinfo);
//#if defined(_CONSOLETASK_ENABLE_)
	BaseGPIO(GPIOPIN gpiopin, ConsoleTask * pTask);
	BaseGPIO(GPIOINFO gpioinfo, ConsoleTask * pTask);
	BaseGPIO(GPIOINFO gpioinfo, ConsoleTask * pTask, string name);
//#endif

	virtual ~BaseGPIO();

	void Timer(BaseTimer timer);
	BaseTimer * getTimerHandler(void);
	void ToggleGPIO(void);
	void setGPIO(void);
	void resetGPIO(void);
	void putGQueue(GPIOStruct gpioinfo);
	GPIOStruct getGQueue(void);
	uint8_t getlenGQueue(void);

	void updateValue(void);
	GPIO_VAL getValue();
	BOOL getEnabled(void);
	void setEnabled(BOOL flag);
	GPIODIRECTION getDirection(void);
	void setDirection(GPIODIRECTION direction);

	void Run(void);
};

#endif

#endif /* TWARELABLIB_BASEGPIO_H_ */
