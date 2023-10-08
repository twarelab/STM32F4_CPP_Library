/*
 * crc16.h
 *
 *  Created on: 2022. 2. 10.
 *      Author: james
 */

#ifndef TWARELABLIB_INCLUDE_CRC32_H_
#define TWARELABLIB_INCLUDE_CRC32_H_

#include <stdint.h>

uint32_t CRC32_Conversion(uint8_t *data, uint16_t length);
uint32_t CRC32_Conversion(uint8_t *data, uint16_t length, uint32_t initCRC);
uint32_t CRC32_ConversionWithInitValue(uint8_t *data, uint16_t length, uint32_t initCRC);

#endif /* TWARELABLIB_INCLUDE_CRC16_H_ */
