/*
 * TypeConverter.h
 *
 *  Created on: Oct 28, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_COMMON_TYPECONVERTER_H_
#define TWLABCPPLIB_COMMON_TYPECONVERTER_H_

#include <stdint.h>

void convertInt16ToByteArray(uint8_t *buf, uint16_t val);
uint16_t convertByteArrayToInt16(uint8_t * buf);
void convertInt32ToByteArray(uint8_t *buf, uint32_t val);
uint32_t convertByteArrayToInt32(uint8_t * buf);


#endif /* TWLABCPPLIB_COMMON_TYPECONVERTER_H_ */
