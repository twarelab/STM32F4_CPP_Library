/*
 * ATCmdTask.h
 *
 *  Created on: Aug 9, 2022
 *      Author: jameskim
 */

#ifndef TWLABCPPLIB_EXTENDEDCLASS_ATCMDTASK_H_
#define TWLABCPPLIB_EXTENDEDCLASS_ATCMDTASK_H_

#include <BaseCmdTask.h>

#include <ConsoleTask.h>

typedef enum{
	ATCOM_STATE_IDLE,
	ATCOM_STATE_START,
	ATCOM_STATE_CMDRCVD,
	ATCOM_STATE_CMDPARSED,
	ATCOM_STATE_REPLYWAIT,
	ATCOM_STATE_DONE,
	ATCOM_STATE_INVALIDCMD,
} ATCOM_State;

typedef enum{
	ATCOM_SUBSTATE_IDLE,
	ATCOM_SUBSTATE_PARAMPARSED,
	ATCOM_SUBSTATE_SETCMD,
	ATCOM_SUBSTATE_CMDDONE,
	ATCOM_SUBSTATE_PUTREPLY,
} ATCOM_SubState;

typedef enum{
	CMD_GET,
	CMD_SET,
} CMD_Type;

typedef struct{
	char cmdbuf[20];
	char parambuf[236];
	int cmdlen;
	int paramlen;
	CMD_Type cmdtype;
} CMD_Struct;

typedef struct{
	char strlist[10][65];
	int strnum;
} STRING_Struct;

class ATCmdTask: public BaseCmdTask {
protected:
	ATCOM_State State;
	ATCOM_SubState SubState;
	CMD_Struct cmdstruct;
	BOOL CRFlag;
	BOOL LFFlag;
	uint8_t tmpBuf[256];
	uint8_t idx;
	char delimiter[3];
	char paramdelimiter[2] = ",";
	char IPDelimiter[2] = ".";
	char subparamdelimiter[2] = "-";
public:
	ATCmdTask();
	ATCmdTask(BaseUART * pUart, ConsoleTask * pTask);
	virtual ~ATCmdTask();

	BOOL findChar(char * chrs, char ch);
	void splitString(STRING_Struct * pStrInfo, char * Str, char * delimeter);

	/*
	 * Param Processing Functions
	 *
	 */
	BOOL makeIPAddr(uint8_t * strIPAddr, uint8_t * IPAddr);
	/* End of Param Processing Functions */

	virtual void processCmd(void);
	void parsingCmd(void);

	void run(void);
};

#endif /* TWLABCPPLIB_EXTENDEDCLASS_ATCMDTASK_H_ */
