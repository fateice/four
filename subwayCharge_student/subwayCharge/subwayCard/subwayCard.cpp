#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;

ST_SUBWAY_CARD g_cardList[MAX_CARD_NUM];

TListHead g_idleCardList;				//˫���������еĿ�
TListHead g_usredCardList;				//˫������ʹ���еĿ�
bool firstRun = true;					//�����ǵ�һ������

/*
@ ��ʼ��g_cardList
@ ����ֵ: ��
*/
void initCardList()
{
	for(int i=0;i<MAX_CARD_NUM;i++){
		g_cardList[i].enCard = EN_CARD_TYPE_BUTT;
		g_cardList[i].cardNo = i;
		g_cardList[i].usrFlag = false;
		g_cardList[i].balance = 0;
	}
}

/*
@ ��ʼ�����еĿ�����
@ ��Σ�g_idleCardList�ĵ�ַ
@ ����ֵ: ��
*/
void initIdleCardList(TListHead *p_idleCardList)
{
	TListHead *tmp;
	InitListHead(p_idleCardList);

	for(int i=0;i<MAX_CARD_NUM;i++)
	{
		tmp = (TListHead *)malloc(sizeof(TListHead));
		if(NULL == tmp)
		{
			return;
		}
		tmp->cardNo = i;
		ListAdd(tmp,p_idleCardList,p_idleCardList->next);
	}
	p_idleCardList->cardNo = 100;//ͷ���������������������м���Ԫ��
}

/*
@ ��ʼ��ʹ���еĿ�����
@ ��Σ�g_usredCardList�ĵ�ַ
@ ����ֵ: ��
*/
void initUsredCardList(TListHead *p_usredCardList)
{
	InitListHead(p_usredCardList);
	p_usredCardList->cardNo = 0;//ͷ���������������������м���Ԫ��
}

/*
@ �������������
@ ����ֵ: ��
*/
void freeLists()
{
	ListClear(&g_idleCardList);
	g_idleCardList.cardNo = 0;
	ListClear(&g_usredCardList);
	g_usredCardList.cardNo = 0;
}

/*
@ ������������ӡ���������ڵ���
@ ����ֵ: ��
*/
void printLists()
{
	puts("g_idleCardList������Ԫ�أ���һ���Ǳ���:");
	ListPrint(&g_idleCardList);
	puts("g_usredCardList������Ԫ�أ���һ���Ǳ���:");
	ListPrint(&g_usredCardList);
}
/*
@ ��ʼ�����п���Ϣ
@ ����ֵ: ��
*/
void InitCardManagerInfo()
{
	initCardList();

	if(!firstRun)
	{
		freeLists();
	}
	firstRun = false;

	initIdleCardList(&g_idleCardList);
	initUsredCardList(&g_usredCardList);
	/*for(int i=0;i<MAX_CARD_NUM;i++){
	    TListHead* tmp=new TListHead();
		tmp->cardNo=i;
		ListAddHead(tmp,g_idleCardList);
	}*/
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
	if(charge>MAX_BALANCE) 
		return EN_RETURN_RECHARGE_OVERFLOW;
	int i=0;
	for(;i<MAX_CARD_NUM;i++){
		if(g_cardList[i].usrFlag==false){
		     cardNo=i;
			 g_cardList[i].usrFlag=true;
			 g_cardList[i].enCard=enCard;
			 g_cardList[i].balance=charge;
			 break;
		}
	}
	if(i==MAX_CARD_NUM) 
		return EN_RETURN_CARD_OVERLOW;
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
    if(cardNo>99)
		return EN_RETURN_INVALID_CARD;
	if(!g_cardList[cardNo].usrFlag)
		return EN_RETURN_INVALID_CARD;
	balance=g_cardList[cardNo].balance;
	enCard=g_cardList[cardNo].enCard;
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
	if(g_cardList[cardNo].usrFlag==false){
	    return -1;
	}
	else{
		g_cardList[cardNo].usrFlag=false;
		g_cardList[cardNo].balance=0;
		g_cardList[cardNo].enCard=EN_CARD_TYPE_BUTT;
	}    
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
	if(cardType[0]>='a'&&cardType[0]<='z'){
	    cardType[0]-=('a'-'A');
	}
	switch (cardType[0]){
	    case ('A'):
			enCard=EN_CARD_TYPE_SINGLE;
			break;
		case ('B'):
			enCard=EN_CARD_TYPE_ELDER;
			break;
		case ('C'):
			enCard=EN_CARD_TYPE_NOMAL;
			break;
		default:
			return EN_RETURN_INPUT_INVALID_CARDTYPE;
			break;
	}

    return EN_RETURN_SUCC;
}