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
	unsigned int cardNo=0;
    //识别卡类型 GetCardType
	EN_CARD_TYPE enCard;
	if(GetCardType(unCmd.stCmdCreateCard.cardType,enCard)==EN_RETURN_INPUT_INVALID_CARDTYPE){
		GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_INPUT_INVALID_CARDTYPE, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
		return;
	}
	if(enCard==EN_CARD_TYPE_SINGLE||enCard==EN_CARD_TYPE_BUTT){
		GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_INPUT_INVALID_CARDTYPE, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
		return;
	}
    //办卡 AssignCard
	EN_RETURN_CODE retCode = AssignCard(cardNo,enCard,unCmd.stCmdCreateCard.cardCharge);

    //输出字符串
    GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, retCode, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
    return;
}