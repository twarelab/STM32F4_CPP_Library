/*
 * FuyuStepMotor.h
 *
 *  Created on: 2023. 8. 6.
 *      Author: james
 */

#ifndef EXTENDEDCLASS_FUYUSTEPMOTOR_H_
#define EXTENDEDCLASS_FUYUSTEPMOTOR_H_

#include <ConsoleTask.h>
#include <BallScrewPWM.h>
#include <BaseGPIO.h>

typedef enum {
	FY_X_RIGHT	= HIGH,
	FY_X_LEFT	= LOW,
} FUYU_XDIR;

typedef enum {
	FY_Y_BACK	= HIGH,
	FY_Y_FRONT	= LOW,
} FUYU_YDIR;

typedef enum {
	FY_Z_UP 	= HIGH,
	FY_Z_DOWN 	= LOW,
} FUYU_ZDIR;

typedef enum {
	FY_DETECTED	= HIGH,
	FY_UNDETECTED	= LOW,
} FUYU_SENSORSTATE;

typedef enum {
	FY_POS_INC = HIGH,
	FY_POS_DEC = LOW,
} FUYU_POSDIR;

#define FY_XPOS_LIMIT	550
#define FY_YPOS_LIMIT	450
#define FY_ZPOS_LIMIT	150

#define FY_RESOLUTION	20

#define FY_CYCLE_PULSECOUNT	40

#define FY_XRESOLUTION	8
#define FY_YRESOLUTION 8
#define FY_ZRESOLUTION 100

class FuyuStepMotor {
protected:
	string name;

	BaseGPIO DirectionGpio;
	BaseGPIO LowLimitGpio;
	BaseGPIO HighLimitGpio;

	BOOL bLowLimitDetected;
	BOOL bHighLimitDetected;
	BOOL bPosInitialized;

	BOOL ToLowLimit;
	BOOL ToHighLimit;

	uint16_t limitCount;
	uint16_t Position;

	ConsoleTask * CTask;

public:
	BallScrewPWM PwmSignal;
	BOOL CurrentDirection;

public:
	FuyuStepMotor();
	FuyuStepMotor(ConsoleTask * pTask, string name);
	virtual ~FuyuStepMotor();

	string getName(void);
	void setPWM(TIM_TypeDef *TIMx, uint32_t Channels);
	void setDirectionGpio(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);
	void setLowLimitGpio(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);
	void setHighLimitGpio(GPIO_TypeDef* port, uint32_t pin, GPIODIRECTION direction);

	void setToLowLimitDirection(BOOL flag);
	BOOL getToLowLimitDirection(void);

	void setToHighLimitDirection(BOOL flag);
	BOOL getToHighLimitDirection(void);

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

	void setLowLimitDetected(BOOL flag);
	BOOL getLowLimitDetected(void);
	void setHighLimitDetected(BOOL flag);
	BOOL getHighLimitDetected(void);

	void setPositionInitialized(BOOL flag);
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
	BaseGPIO * getLowLimitGpioPtr(void);
	BaseGPIO * getHighLimitGpioPtr(void);
	BallScrewPWM * getPWMPtr(void);

	void Run(void);

protected:
	void setPWMCurrentPulseCount(uint32_t pulsecount);

};

#endif /* EXTENDEDCLASS_FUYUSTEPMOTOR_H_ */
