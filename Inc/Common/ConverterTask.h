/*
 * ConverterTask.h
 *
 *  Created on: Dec 27, 2022
 *      Author: jameskim
 */

#ifndef CONVERTERTASK_H_
#define CONVERTERTASK_H_

#include <twarelabType.h>
#include <ValueConverter.h>

#define BAUDRATELISTCOUNT			16
#define FLOWCTRLLISTCOUNT			5
#define PARITYLISTCOUNT				3
#define SAMPLINGINTERVALLISTCOUNT	5
#define SAMPLINGCONDITIONLISTCOUNT	2
#define UPLOADPROTOCOLCOUNT			2
#define TARGUARTCOUNT				5
#define FLASHPROTECTOPTIONCOUNT		4

class ConverterTask {
protected:
public:
	ValueConverter BaudRate;
	ValueConverter FlowCtrl;
	ValueConverter Parity;
	ValueConverter SamplingInterval;
	ValueConverter SamplingCondition;
	ValueConverter UploadProtocol;
	ValueConverter TargetUart;
	ValueConverter FlashProtectOption;
public:
	ConverterTask();
	virtual ~ConverterTask();
	};

#endif /* CONVERTERTASK_H_ */
