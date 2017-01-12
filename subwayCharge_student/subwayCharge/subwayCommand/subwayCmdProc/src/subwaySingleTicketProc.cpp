#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
#include "subwayCmdParse.h"
#include "subwayline.h"
#include "subwayPrice.h"
#include "subwayCommon.h"
#include "subwayOutput.h"
#include "subwayError.h"
using namespace std;

/*
@ 办理单程票
@ 入参：unCmd, 命令内容
@ 出参: returnStr
@ 返回值: 无
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
	unsigned int distance=0;
	int ticketPrice=0;
	EN_RETURN_CODE returnCode;

	unsigned int cardNo;
	
	//returnCode=GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation,unCmd.stCmdSingleTicket.dstStation,distance);
	if(GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation,unCmd.stCmdSingleTicket.dstStation,distance)==EN_RETURN_INNER_ERR)
		returnCode=EN_RETURN_INVALID_DIS;
    //获取两个站点间的里程数 GetSubwayStationDis

     //获取两个站点间的基本票价  GetBasePrice
	ticketPrice=GetBasePrice(distance);
	if(ticketPrice==-1)
		returnCode=EN_RETURN_INNER_ERR;
	// getnewcard return code -1 创建新卡失败

    //办单程卡 AssignCard
	AssignCard(cardNo,EN_CARD_TYPE_SINGLE,ticketPrice);
    //输出字符串
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, EN_RETURN_SUCC, cardNo, EN_CARD_TYPE_SINGLE,ticketPrice, returnStr);


    return;
}