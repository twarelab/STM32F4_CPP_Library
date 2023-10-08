/*
 * TaskManager.h
 *
 *  Created on: 2022. 2. 19.
 *      Author: james
 */

#ifndef TWARELABLIB_TASKMANAGER_H_
#define TWARELABLIB_TASKMANAGER_H_

#include "twarelabType.h"
#include "BaseTask.h"
#include <ConsoleTask.h>

class TaskManager {
protected:
	uint8_t TaskCount;
	BaseTask * Tasks[MAX_TASK_NUM];

	ConsoleTask * CTask;
public:
	TaskManager();
	TaskManager(ConsoleTask * pTask);
	virtual ~TaskManager();

	void RegisterTask(BaseTask * pTask);
	void RunTasks(void);

	uint8_t getTaskCount(void);
};

#endif /* TWARELABLIB_TASKMANAGER_H_ */
