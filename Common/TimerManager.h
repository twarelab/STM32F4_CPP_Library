/*
 * TimerManager.h
 *
 *  Created on: Feb 19, 2022
 *      Author: james
 */

#ifndef TWARELABLIB_TIMERMANAGER_H_
#define TWARELABLIB_TIMERMANAGER_H_

#include "twarelabType.h"
#include "BaseTimer.h"
#include "stdio.h"


class TimerManager {
protected:
	uint8_t _100USECTimerCount;
	BaseTimer * _100USECTimerList[MAX_TIMER_NUM];
	uint8_t MSECTimerCount;
	BaseTimer * MSECTimerList[MAX_TIMER_NUM];
	uint8_t SECTimerCount;
	BaseTimer * SECTimerList[MAX_TIMER_NUM];
public:
	TimerManager();
	virtual ~TimerManager();

	void Register100USECTimer(BaseTimer* pTimer);
	void RegisterMSECTimer(BaseTimer* pTimer);
	void RegisterSECTimer(BaseTimer* pTimer);

	void Update100USECTimers(void);
	void UpdateMSECTimers(void);
	void UpdateSECTimers(void);

	uint8_t get100USECTimerCount(void);
	uint8_t getMSECTimerCount(void);
	uint8_t getSECTimerCount(void);
};


#endif /* TWARELABLIB_TIMERMANAGER_H_ */
