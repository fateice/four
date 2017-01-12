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
@ 办理普通卡
@ 入参：unCmd, 命令内容
@ 出参: returnStr
@ 返回值: 无
*/
void ProcCreateCardCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //识别卡类型 GetCardType
	
	EN_CARD_TYPE enCard;
	GetCardType(unCmd.stCmdCreateCard.cardType,enCard);
    //办卡 AssignCard
	unsigned int cardNo=0;
	AssignCard(cardNo,enCard,unCmd.stCmdCreateCard.cardCharge);

    //输出字符串
    GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_SUCC, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
    return;
}