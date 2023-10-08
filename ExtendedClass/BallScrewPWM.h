/*
 * BallScrewPWM.h
 *
 *  Created on: 2023. 8. 6.
 *      Author: james
 */

#ifndef EXTENDEDCLASS_BALLSCREWPWM_H_
#define EXTENDEDCLASS_BALLSCREWPWM_H_

#include <BasePWM.h>

class BallScrewPWM: public BasePWM {
protected:
	uint32_t frequency;
public:
	BallScrewPWM();
	BallScrewPWM(TIM_TypeDef *TIMx, uint32_t Channels, ConsoleTask * pTask, string name);
	virtual ~BallScrewPWM();

	virtual void EnableChannel(void);

	virtual void setFrequency(uint32_t frequency);
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

#endif /* EXTENDEDCLASS_BALLSCREWPWM_H_ */
