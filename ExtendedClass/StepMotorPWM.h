/*
 * StepMotorPWM.h
 *
 *  Created on: Jul 12, 2023
 *      Author: James Kim
 */

#ifndef EXTENDEDCLASS_STEPMOTORPWM_H_
#define EXTENDEDCLASS_STEPMOTORPWM_H_

#include <ConsoleTask.h>
#include <BasePWM.h>
#include <BaseGPIO.h>

typedef enum {
	X_RIGHT	= LOW,
	X_LEFT	= HIGH,
} XDIR;

typedef enum {
	Y_BACK	= HIGH,
	Y_FRONT	= LOW,
} YDIR;

typedef enum {
	Z_TOP 	= HIGH,
	Z_BOTTOM 	= LOW,
} ZDIR;

typedef enum {
	DETECTED	= 0,
	UNDETECTED	= 1,
} SENSORSTATE;

#define XPOS_LIMIT	420
#define YPOS_LIMIT	240
#define ZPOS_LIMIT	100

#define XRESOLUTION	8
#define YRESOLUTION 8
#define ZRESOLUTION 100

class StepMotorPWM {
protected:
	BaseGPIO DirectionGpio;
	BaseGPIO P0Gpio;
	string name;

	ConsoleTask * CTask;

	BOOL bDetected;
	BOOL bPosInitialized;

	uint16_t limitCount;
	uint16_t Position;
public:
	BasePWM PwmSignal;
	BOOL CurrentDirection;

public:
	StepMotorPWM();
	StepMotorPWM(ConsoleTask * pTask, string name);
	virtual ~StepMotorPWM();

	string getName(void);

	void setPWM(TIM_TypeDef *TIMx, uint32_t Channels);
	void setDirectionGpio(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);
	void setP0Gpio(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);

	void updateFrequency(uint32_t frequency);

	void setDirection(BOOL flag);
	BOOL getDirection(void);

	void setDirectionPin(BOOL flag);
	BOOL getDirectionPin(void);

	void setDetectedFlag(BOOL flag);
	BOOL getDetectedFlag(void);

	void setPosition(uint16_t pos);
	uint16_t getPosition(void);

	void setLimitCount(uint16_t count);
	uint16_t getLimitCount(void);

	void updatePosition(void);

	BOOL getPositionInitialized(void);

	uint32_t getPWMPulseCount(void);
	void setPWMPulseCount(uint32_t pulsecount);
	uint32_t getPWMCurrentPulseCount(void);
	void updatePWMCurrentPulseCount(BOOL direction);

	void setPWMTotalPulseCount(uint32_t pulsecount);
	uint32_t getPWMTotalPulseCount(void);
	void updateTotalPulseCount(BOOL direction);

	void startPWM(void);
	void stopPWM(void);

	BaseGPIO * getDirectionGpioPtr(void);
	BaseGPIO * getP0GpioPtr(void);
	BasePWM * getPWMPtr(void);

	void Run(void);

protected:
	void setPWMCurrentPulseCount(uint32_t pulsecount);
	};

#endif /* EXTENDEDCLASS_STEPMOTORPWM_H_ */
