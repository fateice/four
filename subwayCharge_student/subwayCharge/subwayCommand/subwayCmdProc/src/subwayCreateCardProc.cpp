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
@ ������ͨ��
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateCardCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
	unsigned int cardNo=0;
    //ʶ������ GetCardType
	EN_CARD_TYPE enCard;
	if(GetCardType(unCmd.stCmdCreateCard.cardType,enCard)==EN_RETURN_INPUT_INVALID_CARDTYPE){
		GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_INPUT_INVALID_CARDTYPE, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
		return;
	}
	if(enCard==EN_CARD_TYPE_SINGLE||enCard==EN_CARD_TYPE_BUTT){
		GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_INPUT_INVALID_CARDTYPE, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
		return;
	}
    //�쿨 AssignCard
	EN_RETURN_CODE retCode = AssignCard(cardNo,enCard,unCmd.stCmdCreateCard.cardCharge);

    //����ַ���
    GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, retCode, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
    return;
}