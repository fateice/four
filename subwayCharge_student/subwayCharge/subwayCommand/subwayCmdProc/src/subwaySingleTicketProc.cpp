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
	EN_RETURN_CODE returnCode;

	unsigned int cardNo;
	
	//returnCode=GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation,unCmd.stCmdSingleTicket.dstStation,distance);
	if(GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation,unCmd.stCmdSingleTicket.dstStation,distance)==EN_RETURN_INNER_ERR)
		returnCode=EN_RETURN_INVALID_DIS;
    //��ȡ����վ��������� GetSubwayStationDis

     //��ȡ����վ���Ļ���Ʊ��  GetBasePrice
	ticketPrice=GetBasePrice(distance);
	if(ticketPrice==-1)
		returnCode=EN_RETURN_INNER_ERR;
	// getnewcard return code -1 �����¿�ʧ��

    //�쵥�̿� AssignCard
	AssignCard(cardNo,EN_CARD_TYPE_SINGLE,ticketPrice);
    //����ַ���
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, EN_RETURN_SUCC, cardNo, EN_CARD_TYPE_SINGLE,ticketPrice, returnStr);


    return;
}