/*
 * BaseQueue.h
 *
 *  Created on: Apr 12, 2022
 *      Author: jameskim
 */

#ifndef TWARELABLIB_BASEQUEUE_H_
#define TWARELABLIB_BASEQUEUE_H_

#include <twarelabType.h>
#include <string.h>

//#define QUEUE_SIZE	2048

class BaseQueue {
protected:
	uint16_t in;
	uint16_t out;
	uint16_t queuesize;
	BOOL bDataReady;
	uint8_t queue[QUEUE_SIZE];
public:
	BaseQueue();
	virtual ~BaseQueue();

	void push(uint8_t data);
	void bulkpush(uint8_t * buf, uint16_t size);
	uint8_t pop(void);
	void bulkpop(uint8_t * buf, uint16_t size);
	uint16_t size(void);
	uint16_t getIn(void);
	uint16_t getOut(void);
	uint16_t freesize(void);
	BOOL checkVal(uint8_t ch);
	void clearQueue(void);
	uint8_t * getQueuePtr(void);
};

#endif /* TWARELABLIB_BASEQUEUE_H_ */
