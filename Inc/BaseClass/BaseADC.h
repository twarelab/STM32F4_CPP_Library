/*
 * BaseADC.h
 *
 *  Created on: Apr 4, 2022
 *      Author: jameskim
 */

#ifndef TWARELABLIB_BASEADC_H_
#define TWARELABLIB_BASEADC_H_

#include <twarelabType.h>

typedef struct _READABLEADC_
{
	uint8_t ADCDecimal;
	uint8_t ADCFraction;
} READABLEADC;

typedef struct _ADCDATA_STRUCT_
{
	uint16_t RawADCValue;
	double floatValue;
	READABLEADC HumanADCValue;
	uint32_t cumulativeADCValue;
} ADCDATA_STRUCT;

class BaseADC {
protected:
	BOOL enable;
	SAMPLINGINTERVAL samplinginterval;
	SAMPLINGCONDITION samplingcondition;
	ADCDATA_STRUCT data;
public:
	BaseADC();
	virtual ~BaseADC();

	void setEnable(BOOL flag);
	BOOL getEnable(void);

	void setSamplingInterval(SAMPLINGINTERVAL interval);
	SAMPLINGINTERVAL getSamplingInterval(void);

	void setSamplingCondition(SAMPLINGCONDITION condition);
	SAMPLINGCONDITION getSamplingCondition(void);

	void setRawADCValue(uint16_t value);

	uint16_t getRawADCValue(void);
	double getFloatADCValue(void);
	uint8_t getHumanADCDecimalValue(void);
	uint8_t getHumanADCFractionValue(void);
};

#endif /* TWARELABLIB_BASEADC_H_ */
