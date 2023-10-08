/*
 * FlashHandler.h
 *
 *  Created on: May 15, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_COMMON_FLASHHANDLER_H_
#define TWLABCPPLIB_COMMON_FLASHHANDLER_H_

#include <twarelabType.h>
#include <ConsoleTask.h>

//#include <stm32f4xx_hal_def.h>
//#include <stm32f4xx_hal_iwdg.h>


#define ADDR_FLASH_SECTOR_0		((uint32_t)0x08000000)
#define ADDR_FLASH_SECTOR_1		((uint32_t)0x08004000)
#define ADDR_FLASH_SECTOR_2		((uint32_t)0x08008000)
#define ADDR_FLASH_SECTOR_3		((uint32_t)0x0800C000)
#define ADDR_FLASH_SECTOR_4		((uint32_t)0x08010000)
#define ADDR_FLASH_SECTOR_5		((uint32_t)0x08020000)
#define ADDR_FLASH_SECTOR_6		((uint32_t)0x08040000)
#define ADDR_FLASH_SECTOR_7		((uint32_t)0x08060000)
#define ADDR_FLASH_SECTOR_8		((uint32_t)0x08080000)
#define ADDR_FLASH_SECTOR_9		((uint32_t)0x080A0000)
#define ADDR_FLASH_SECTOR_10	((uint32_t)0x080C0000)
#define ADDR_FLASH_SECTOR_11	((uint32_t)0x080E0000)
#define ADDR_FLASH_SECTOR_12	((uint32_t)0x08100000)

#define APPLICATION_ADDR		0x08020000
#define BACKUP1_ADDR			0x08080000
#define BACKUP2_ADDR			0x080A0000
#define BACKUP3_ADDR			0x080C0000
#define BACKUP4_ADDR			0x080E0000

typedef struct {
	uint32_t sectorNum;
	uint32_t startAddr;
	uint32_t endAddr;
} SectorStruct;

class FlashHandler {
protected:
	ConsoleTask * CTask;
	BOOL bIWDGEnable;
	IWDG_HandleTypeDef hiwdg;
public:
	FlashHandler();
	FlashHandler(ConsoleTask * CTask);
	virtual ~FlashHandler();

	void setIWDGEnable(BOOL flag);
	BOOL getIWDGEnable(void);
	void setIWDGHandler(IWDG_HandleTypeDef hIWDG);

	HAL_StatusTypeDef EraseFlash(uint32_t startAddr, uint32_t size);
	HAL_StatusTypeDef WriteFlash(uint32_t startAddr, uint32_t len, uint8_t * data);
	HAL_StatusTypeDef ReadFlash(uint32_t startAddr, uint32_t len, uint8_t * data);

	HAL_StatusTypeDef EnableWriteProtect(uint32_t WRPSectors);
	HAL_StatusTypeDef DisableWriteProtect(uint32_t WRPSectors);
	uint32_t GetWriteProtect(uint32_t WRPSectors);

	HAL_StatusTypeDef EnableReadProtect(void);
	HAL_StatusTypeDef DisableReadProtect(void);
	uint32_t GetReadProtect(void);

	uint32_t GetSector(uint32_t Address);
	uint32_t GetSectorSize(uint32_t Sector);

};

#endif /* TWLABCPPLIB_COMMON_FLASHHANDLER_H_ */
