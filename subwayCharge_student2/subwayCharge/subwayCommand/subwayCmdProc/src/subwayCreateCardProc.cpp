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
    //ʶ������ GetCardType
	
	EN_CARD_TYPE enCard;
	GetCardType(unCmd.stCmdCreateCard.cardType,enCard);
    //�쿨 AssignCard
	unsigned int cardNo=0;
	AssignCard(cardNo,enCard,unCmd.stCmdCreateCard.cardCharge);

    //����ַ���
    GetOutputResultStr(EN_CMD_TYPE_CREATE_CARD, EN_RETURN_SUCC, cardNo, enCard, unCmd.stCmdCreateCard.cardCharge, returnStr);
    return;
}