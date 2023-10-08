/*
 * crc16.h
 *
 *  Created on: 2022. 2. 10.
 *      Author: james
 */

#ifndef TWARELABLIB_INCLUDE_CRC16_H_
#define TWARELABLIB_INCLUDE_CRC16_H_

#include <stdint.h>

uint16_t CRC16_Conversion(uint8_t *data, uint16_t length);

#endif /* TWARELABLIB_INCLUDE_CRC16_H_ */
