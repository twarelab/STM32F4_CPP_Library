/*
 * ValueConverter.h
 *
 *  Created on: Dec 27, 2022
 *      Author: jameskim
 */

#ifndef VALUECONVERTER_H_
#define VALUECONVERTER_H_

#include <twarelabType.h>

class ValueConverter {
protected:
	CONVERSIONSTRUCT * pList;
	uint8_t ListCount;
public:
	ValueConverter();
	virtual ~ValueConverter();

	void setConversionList(CONVERSIONSTRUCT * pList);
	void setListCount(uint8_t count);

	uint32_t getValueByIndex(uint8_t index);
	uint8_t getIndexByValue(uint32_t value);
	string getNameByIndex(uint8_t index);
	string getNameByValue(uint32_t value);

};

#endif /* VALUECONVERTER_H_ */
