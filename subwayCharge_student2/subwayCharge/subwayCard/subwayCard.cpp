#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;


/*
@ ��ʼ�����п���Ϣ
@ ����ֵ: ��
*/
void InitCardManagerInfo()
{
	//for(int i=0;i<MAX_CARD_NUM;i++){
	//    g_cardList[i].cardNo=i;
	//}
	//for(int i=0;i<MAX_CARD_NUM;i++){
	//    TListHead* tmp=new TListHead();
	//	tmp->cardNo=i;
	//	ListAddHead(tmp,g_idleCardList);
	//}
	
}

/*
@ ���������俨�źͿ���Ϣ
@ ��Σ�enCard,������; charge: ��ֵ
@ ����: cardNo, ����Ŀ���
@ ����ֵ: EN_RETURN_SUCC������ɹ�; EN_RETURN_CARD_OVERLOW, ����ʧ��;
*/
EN_RETURN_CODE AssignCard(unsigned int &cardNo, EN_CARD_TYPE enCard, unsigned int charge)
{
	
	//if(ListEmpty(g_idleCardList)){
	//    return EN_RETURN_CARD_OVERLOW;
	//}
	//TListHead* tmp=g_idleCardList;
	//g_idleCardList=g_idleCardList->next;
	//tmp->next=NULL;
	//ListAddTail(g_usredCardList,tmp);
	//cardNo=tmp->cardNo;
	cardNo=1;
    return EN_RETURN_SUCC;
}

/*
@ ��ֵ
@ ��Σ�cardNo,����; recharge: ��ֵ
@ ����: ��
@ ����ֵ: EN_RETURN_SUCC���ɹ�; ����, ʧ��;
*/
EN_RETURN_CODE RechargeCard(unsigned int cardNo, unsigned int recharge)
{
    
    return EN_RETURN_SUCC;
}

/*
@ ��ȡ�����
@ ��Σ�cardNo,����; 
@ ����: balance: ���
        enCard:  ������
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INVALID_CARD, ʧ��;
*/
EN_RETURN_CODE GetCardInfo(unsigned int cardNo, unsigned int &balance, EN_CARD_TYPE &enCard)
{
    
    return EN_RETURN_SUCC;
}

/*
@ ���۷�
@ ��Σ�cardNo,����; enCard, ������; deductPrice, �۷�Ʊ��
@ ����: balance, �۷Ѻ�����
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INVALID_CARD, EN_RETURN_BALANCE_NOT_ENOUGH, ʧ��;
*/
EN_RETURN_CODE DeductCard(unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int deductPrice, unsigned int &balance)
{
    
    return EN_RETURN_SUCC;
}

/*
@ ɾ������Ϣ
@ ��Σ�cardNo,����; 
@ ����: ��
@ ����ֵ: 0���ɹ�; -1, ʧ��;
*/
int DeleteCard(unsigned int cardNo)
{
    
    return 0;
}

/*
@ ��ȡ�������ַ���
@ ��Σ�enCard,������; 
@ ����: ��
@ ����ֵ: �������ַ���;
*/
char* GetCardTypeStr(EN_CARD_TYPE enCard)
{
	char* ret;
	switch(enCard){
	    case(EN_CARD_TYPE_SINGLE):
			ret="���̿�";
			break;
		case(EN_CARD_TYPE_ELDER):
			ret="���꿨";
			break;
		case(EN_CARD_TYPE_NOMAL):
			ret="��ͨ��";
			break;
		default:
			ret="unknown";
	}
    return ret;
}

/*
@ ���ݿ������ַ���, ʶ������
@ ��Σ�cardType,      �������ַ���; 
@ ����: enCard,        ������
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INPUT_INVALID_CARDTYPE, ʧ��;
*/
EN_RETURN_CODE GetCardType(char cardType[], EN_CARD_TYPE &enCard)
{
	switch (cardType[0]){
	    case 'A':
			enCard=EN_CARD_TYPE_SINGLE;
			break;
		case 'B':
			enCard=EN_CARD_TYPE_ELDER;
			break;
		case 'C':
			enCard=EN_CARD_TYPE_NOMAL;
			break;
		default:
			break;
	}

    return EN_RETURN_SUCC;
}