/*
 * twarelabType.h
 *
 *  Created on: Nov 2, 2021
 *      Author: jameskim
 */

#ifndef INC_TWARELABTYPE_H_
#define INC_TWARELABTYPE_H_

#include <string>

#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_dma.h"

using namespace std;

#include <stdint.h>

#define MAX_TASK_NUM	30
#define MAX_TIMER_NUM	255

#define UART_NUM		4

#define ETH_NUM			4

#define MAX_G_QUEUE_LEN 10

#define QUEUE_SIZE	(2048 + 1)
//#define QUEUE_SIZE	(1024 + 1)
//#define QUEUE_SIZE	(1024)

#define DMA_BUF_SIZE			(1024)
#define ETH_MAX_BUF_SIZE		512

#ifndef DATA_BUF_SIZE
#define DATA_BUF_SIZE			1024
#endif

#define INITIAL_GPIO_NUM	6

#define MAX_MSG_LEN		1024

#define 	_STX_	0x55AA

typedef enum
{
	False = 0,
	True = 1
} BOOL;

typedef enum
{
	HIGH = 1,
	LOW = 0
} GPIO_VAL;

#ifndef GPIO_PinState
	#define GPIO_PIN_RESET	0
	#define GPIO_PIN_SET	1
#endif

typedef enum
{
	SEC = 0,
	MSEC = 1
} TIMEDEF;

typedef struct _RETRY_INFO
{
	BOOL enabled;
	BOOL triggered;
	TIMEDEF timetype;
	uint16_t timecriteria;
	uint16_t timecount_msec;
	uint16_t timecount_sec;
} RETRY_INFO, TIMER_INFO;

typedef struct _TASK_FLAG_
{
	BOOL enabled;
	BOOL moduleInitialized;
	BOOL finished;
	RETRY_INFO retry;
	void (*phandler)();
} TASK_FLAG;


#define MAX_UART_COUNT		4
#define MAX_GPIO_COUNT		32
#define MAX_ADC_COUNT		8


typedef enum{
	UART1_TX_STATE_IDLE,
	UART1_TX_STATE_READY,
	UART1_TX_STATE_SENT,
	UART1_TX_STATE_DONE
}UART1_TX_State;

typedef enum{
	UART1_RX_STATE_IDLE,
	UART1_RX_STATE_RXCHECK,
	UART1_RX_STATE_DONE
}UART1_RX_State;


typedef enum{
	TYPE_UART		= 0x01,
	TYPE_GPIO		= 0x02,
	TYPE_ADC		= 0x03,
	TYPE_SPI		= 0x04,
	TYPE_UNKNOWN	= 0xFF
}PORTTYPE;

typedef enum{
	UART_1		= 1,
	UART_2		= 2,
	UART_3		= 3,
	UART_4		= 4
} UARTPORT;

typedef enum{
	BR_300		= 0,
	BR_600		= 1,		//9
	BR_1200		= 2,		//7
	BR_2400		= 3,		//6
	BR_4800		= 4,		//5
	BR_9600		= 5,		//4
	BR_19200	= 6,		//3
	BR_38400	= 7,		//2
	BR_57600	= 8,		//1
	BR_115200	= 9,		//0
	BR_230400	= 10,		//8
	BR_460800	= 11,
	BR_921600	= 12,
	BR_1000000	= 13,
	BR_2000000	= 14,
	BR_3000000	= 15
} BAUDRATE;

typedef enum{
	FC_NONE				= 0,
	FC_XONXOFF			= 1,
	FC_RTSCTS			= 2,
	FC_RTSONLY			= 3,
	FC_REVERSERTSONLY	= 4
} FLOWCTRL;

typedef enum {
	DATABIT_7	= 0,
	DATABIT_8	= 1
} DATABIT;

typedef enum {
	PARITY_NONE	= 0,
	PARITY_ODD	= 1,
	PARITY_EVEN	= 2
} PARITY;

typedef enum {
	STOP_0_5	= 0,
	STOP_1_0	= 1,
	STOP_1_5	= 2,
	STOP_2_0	= 3
} STOPBIT;

typedef enum {
	MODE_SERVER		= 0,
	MODE_CLIENT		= 1,
	MODE_MIXED		= 2
} OPMODE;

typedef enum {
	SCM_NONE		= 0,
	SCM_HW			= 1,
	SCM_SW			= 2
} SCM;

typedef enum {
	ST_TCP		= 0,
	ST_UDP		= 1
} SOCK_TYPE;

typedef enum {
	SS_DISCONNECTED		= 0,
	SS_CONNECTED		= 1
} SOCK_STATE;

typedef enum{
	SI_1ms		= 0,
	SI_10ms		= 1,
	SI_100ms	= 2,
	SI_1000ms	= 3,
	SI_5000ms	= 4
} SAMPLINGINTERVAL;

typedef enum{
	G_INPUT		= 0,
	G_OUTPUT	= 1
}GPIODIRECTION;

typedef enum{
	SC_LATEST	= 0,
	SC_AVERAGE	= 1,
} SAMPLINGCONDITION;

typedef enum {
	FLASH_IDLE		= 0,
	FLASH_ERASED	= 1,
	FLASH_PREPARED	= 2,
	FLASH_COPIED	= 3,
} FLASHSTATE;

typedef enum {
	BKP_NONE		= 0,
	BKP_1			= 1,
	BKP_2			= 2
}WORKINGBKP;

/* STATE Definition */
typedef enum {
	STATE_IDLE			= 0,
	STATE_SOCKCREATED 	= 1,
	STATE_CONNECTING	= 2,
	STATE_CONNECTED		= 3,
} PF_STATE;

typedef enum {
	TG_TWARELAB	= 0,
	TG_WIZNET	= 1,
} TARGETGROUP;

typedef enum {
	WTD_NONE	= 0,
	WTD_W5500	= 1,
	WTD_W5100S	= 2,
	WTD_W6100	= 3,
} WIZNET_TARGETDEVICE;

typedef enum {
	S2E_UNKNOWN	= 0,
	S2E_STD		= 1,
	S2E_WIZ		= 2
} S2ETYPE;

typedef struct {
	uint16_t localport;
	uint16_t sendbytes;
	uint8_t TxBuf[DATA_BUF_SIZE];
	uint8_t RxBuf[DATA_BUF_SIZE];
} ETHERSTRUCT;

typedef struct _FLASHINGFIELD_{
	uint32_t FlashingSize;
	uint32_t TargetStartAddr;
	uint8_t FWIndex;
	uint8_t FlashIndex;
	FLASHSTATE FlashState;
}FLASHINGFIELD;

typedef struct _UARTDetail_{
	BAUDRATE baudrate;
	FLOWCTRL flowctrl;
	PARITY parity;
} UARTDETAIL;

typedef struct _ADCDetail_{
	SAMPLINGINTERVAL interval;
	SAMPLINGCONDITION condition;
} ADCDETAIL, ADC_OPTION, ADCOPTION;

typedef struct _PORT_INFO_{
	BOOL enable;
	PORTTYPE type;
	union _Detail_{
		GPIODIRECTION direction;
		UARTDETAIL uartdetail;
	}detail;
} PORT_INFO;

typedef struct _UART_PORT_{
	BOOL enable;
	UARTDETAIL detail;
} UART_PORT, UARTFIELD;

typedef struct _GPIO_PORT_{
	BOOL enable;
	GPIODIRECTION direction;
} GPIO_PORT, GPIOFIELD;

typedef struct _ADC_PORT_ {
	BOOL enable;
} ADC_PORT, ADCFIELD;

typedef struct _I2C_PORT_ {
	BOOL enable;
	uint8_t deviceaddr;
	uint16_t length;
} I2C_PORT, I2CFIELD;

typedef struct _SPI_PORT_ {
	BOOL enable;
	uint8_t reserved[3];
} SPI_PORT, SPIFIELD;

typedef struct _PORT_CONFIG_{
	UART_PORT ifuart;
	UART_PORT uart[MAX_UART_COUNT];
	GPIO_PORT gpio[MAX_GPIO_COUNT];
	ADC_PORT adc[MAX_ADC_COUNT];
} PORT_CONFIG;

typedef struct _PORTCONFIG_ {
	UARTFIELD IFUart;
	UARTFIELD Uart[4];
	GPIOFIELD Gpio[32];
	ADCFIELD Adc[8];
	I2CFIELD I2c;
	SPIFIELD Spi;
	ADCOPTION AdcOption;
}PORTCONFIG;

typedef struct
{
	BOOL enable;
	uint32_t GPIOport;
	uint32_t GPIOnum;
	GPIODIRECTION direction;
	GPIO_VAL value;
} GPIOINFO;

typedef struct
{
	uint32_t GPIOport;
	uint32_t GPIOnum;
	uint32_t ADCChannel;
} ADCINFO;

typedef struct
{
	BOOL enable;
	uint32_t GPIOport;
	uint32_t GPIOnum;
	PORTTYPE type;
} PORTVALIDATION;

typedef struct
{
	GPIO_VAL GPIOvalue;
	uint16_t Duration;
} GPIOStruct;

typedef struct
{
	GPIO_TypeDef * GPIOport;
	uint32_t GPIOnum;
	string gpiotimername;
} GPIOPIN;

typedef struct
{
	uint8_t in;
	uint8_t out;
	GPIOStruct queue[MAX_G_QUEUE_LEN];
}GPIOQUEUE;

typedef struct _dma_buf_
{
	uint16_t in;
	uint16_t out;
	uint8_t buf[DMA_BUF_SIZE];
	BOOL bRcvd;
	uint16_t HC_count;
	uint16_t TC_count;
	uint16_t IDLE_count;
	uint32_t totalBytes;
} dma_buf;

typedef struct _EEPROM_VAR_
{
	uint8_t pos;
	uint8_t len;
} EEPROM_VAR;

typedef struct _CONVERSIONSTRUCT_{
	uint8_t index;
	uint32_t value;
	string name;
}CONVERSIONSTRUCT;

typedef struct _FLASHINGSTRUCT_ {
	uint32_t ReadStartAddr;
	uint32_t WriteStartAddr;
	uint32_t Size;
}FLASHINGSTRUCT;

#define SPI1_DMATXPORT			DMA2
#define SPI1_DMARXPORT			DMA2
#define SPI1_DMATXSTREAM		LL_DMA_STREAM_3
#define SPI1_DMARXSTREAM		LL_DMA_STREAM_0

#define SPI2_DMATXPORT			DMA1
#define SPI2_DMARXPORT			DMA1
#define SPI2_DMATXSTREAM		LL_DMA_STREAM_4
#define SPI2_DMARXSTREAM		LL_DMA_STREAM_3

#define SPI3_DMATXPORT			DMA1
#define SPI3_DMARXPORT			DMA1
#define SPI3_DMATXSTREAM		LL_DMA_STREAM_5
#define SPI3_DMARXSTREAM		LL_DMA_STREAM_0


#endif /* INC_TWARELABTYPE_H_ */
