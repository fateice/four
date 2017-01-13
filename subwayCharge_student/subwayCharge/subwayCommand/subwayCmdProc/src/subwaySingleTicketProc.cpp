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
@ ������Ʊ
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
	unsigned int distance=0;
	int ticketPrice=0;
	EN_RETURN_CODE returnCode=EN_RETURN_SUCC;
	unsigned int cardNo=0;
	returnCode=GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation,unCmd.stCmdSingleTicket.dstStation,distance);
	if(returnCode==EN_RETURN_SUCC)
	{
		//returnCode=EN_RETURN_INVALID_DIS;
	   //��ȡ����վ��������� GetSubwayStationDis

      //��ȡ����վ���Ļ���Ʊ��  GetBasePrice
	ticketPrice=GetBasePrice(distance);
	if(ticketPrice==-1)
		returnCode=EN_RETURN_INNER_ERR;
	// getnewcard return code -1 �����¿�ʧ��

    //�쵥�̿� AssignCard
	returnCode=AssignCard(cardNo,EN_CARD_TYPE_SINGLE,ticketPrice);
    //����ַ���
	}
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, returnCode, cardNo, EN_CARD_TYPE_SINGLE,ticketPrice, returnStr);


    return;
}