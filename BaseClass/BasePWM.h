/*
 * BasePWM.h
 *
 *  Created on: May 28, 2023
 *      Author: James Kim
 */

#ifndef BASEPWM_H_
#define BASEPWM_H_

#include <twarelabType.h>
#include <ConsoleTask.h>

#define STARTSTOPPULSECOUNT	50

#define STEPCONT 5

#define ACCELPORTION	0.1
#define NORMALPORTION	0.8

typedef struct _FREQSTRUCT_{
	uint16_t pulsecount;
	uint32_t freqency;
} FREQSTRUCT;

class BasePWM {
protected:
	ConsoleTask * CTask;
public:
	TIM_TypeDef * pTimer;
	uint32_t Channel;
	uint32_t prevduty;
	uint32_t duty;
	uint32_t autoreload;
	uint32_t pulseCount;
	uint32_t currentCount;
	uint32_t totalPulseCount;
	uint16_t limitCount;

	uint32_t startstopfrequency;
	uint32_t normalfrequency;
	uint32_t currentfrequency;

	BOOL bMoving;
	BOOL CurrentDirection;
	string name;

	FREQSTRUCT FreqList[11];
	uint8_t FreqListCount;

	uint16_t stepPulseCount;

public:
	BasePWM();
	BasePWM(TIM_TypeDef *TIMx, uint32_t Channels, ConsoleTask * pTask, string name);
	virtual ~BasePWM();

	virtual void EnableChannel(void);

	virtual void setFrequency(uint32_t startstopfrequency, uint32_t normalfrequency);

	virtual void updateFrequency(uint32_t frequency);

	virtual void setDuty(uint32_t val);
	virtual uint32_t getDuty(void);

	virtual void setPrevDuty(uint32_t val);
	virtual uint32_t getPrevDuty(void);

	virtual uint32_t getAutoReload(void);

	virtual void setPulseCount(uint32_t val);
	virtual uint32_t getPulseCount(void);

	virtual void setCurrentCount(uint32_t val);
	virtual uint32_t getCurrentCount(void);
	virtual void updateCurrentCount(void);

	virtual void setTotalPulseCount(uint32_t val);
	virtual uint32_t getTotalPulseCount(void);
	virtual void  updateTotalPulseCount();

	virtual void setLimitPulseCount(uint16_t val);
	virtual uint16_t getLimitPulseCount(void);

	virtual void startPWM(void);
	virtual void stopPWM(void);

	virtual BOOL getIsMoving(void);
	virtual void setIsMoving(BOOL flag);

	virtual void setDirection(BOOL flag);
	virtual BOOL getDirection(void);

	virtual void clearFreqList(void);
	virtual void addFreqList(uint16_t count, uint32_t freq);
	virtual int8_t isPulsecountInFreqList(uint16_t count);
	virtual uint32_t getFreqFromList(uint8_t index);
};

#endif /* BASEPWM_H_ */
