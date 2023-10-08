/*
 * BaseTask.h
 *
 *  Created on: 2022. 2. 21.
 *      Author: james
 */

#ifndef TWARELABLIB_BASETASK_H_
#define TWARELABLIB_BASETASK_H_

#include "twarelabType.h"
#include "BaseTimer.h"
#include <TimerManager.h>


class BaseTask {
protected:
	BOOL bEnabled;
	BOOL bModuleInitialized;
	BOOL bFinished;
	BaseTimer timer;
	string name;

public:
	BaseTask();

	virtual ~BaseTask();

	void setEnable(BOOL flag);
	BOOL getEnable(void);

	void setModuleInitialize(BOOL flag);
	BOOL getModuleInitialized(void);

	void setFinish(BOOL flag);
	BOOL getFinish(void);

	void setTimer(BaseTimer timer);
	BaseTimer * getTimerHandle(void);

	void registerTimer(TimerManager *pTM);

	void setName(string name);
	string getName(void);

	void virtual run(void);
};

#endif /* TWARELABLIB_BASETASK_H_ */
