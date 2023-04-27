/*
 * FieldInfo.h
 *
 *  Created on: May 10, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_COMMON_FIELDINFO_H_
#define TWLABCPPLIB_COMMON_FIELDINFO_H_

#include <twarelabType.h>
#include <ConsoleTask.h>

class FieldInfo {
protected:
	uint16_t pos;
	uint16_t len;
	string name;
	ConsoleTask * CTask;
public:
	FieldInfo();
	FieldInfo(uint16_t pos, uint16_t len);
	FieldInfo(uint16_t pos, uint16_t len, string name, ConsoleTask * pTask);
	virtual ~FieldInfo();

	uint16_t getPosition(void);
	uint16_t getLength(void);
	uint16_t getNextPosition(void);
	void printFieldInfo(void);
};

#endif /* TWLABCPPLIB_COMMON_FIELDINFO_H_ */
