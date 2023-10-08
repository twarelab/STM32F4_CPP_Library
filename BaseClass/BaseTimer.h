/*
 * BaseTimer.h
 *
 *  Created on: Feb 19, 2022
 *      Author: james
 */

#ifndef TWARELABLIB_INCLUDE_BASETIMER_H_
#define TWARELABLIB_INCLUDE_BASETIMER_H_

#include <twarelabType.h>
#include "stm32f4xx_ll_tim.h"
#include <string>
using namespace std;

class BaseTimer {
protected:
	BOOL bEnable;
	BOOL bTrigger;
	TIMEDEF timetype;
	uint16_t timecriteria;
	uint16_t timecount;
	string name;
public:
	BaseTimer();
	BaseTimer(string name, BOOL flag, TIMEDEF type, uint16_t criteria, uint16_t count);
	virtual ~BaseTimer();

	void setName(string name);
	string getName(void);

	void setEnable(BOOL flag);
	BOOL getEnable(void);

	void setTrigger(BOOL flag);
	BOOL getTrigger(void);

	void setTimeType(TIMEDEF type);
	TIMEDEF getTimeType(void);

	void setTimeCriteria(uint16_t value);
	uint16_t getTimeCriteria(void);

	void setTimeCount(uint16_t value);
	uint16_t getTimeCount(void);

	uint16_t updateTimeCount(void);

};

#endif /* TWARELABLIB_INCLUDE_BASETIMER_H_ */
