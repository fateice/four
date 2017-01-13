#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;

ST_SUBWAY_CARD g_cardList[MAX_CARD_NUM];

TListHead g_idleCardList;				//双向链表：空闲的卡
TListHead g_usredCardList;				//双向链表：使用中的卡
bool firstRun = true;					//程序是第一次运行

/*
@ 初始化g_cardList
@ 返回值: 无
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
@ 初始化空闲的卡链表
@ 入参：g_idleCardList的地址
@ 返回值: 无
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
	p_idleCardList->cardNo = 100;//头结点的数据域代表这个链表有几个元素
}

/*
@ 初始化使用中的卡链表
@ 入参：g_usredCardList的地址
@ 返回值: 无
*/
void initUsredCardList(TListHead *p_usredCardList)
{
	InitListHead(p_usredCardList);
	p_usredCardList->cardNo = 0;//头结点的数据域代表这个链表有几个元素
}

/*
@ 将两个链表都清空
@ 返回值: 无
*/
void freeLists()
{
	ListClear(&g_idleCardList);
	g_idleCardList.cardNo = 0;
	ListClear(&g_usredCardList);
	g_usredCardList.cardNo = 0;
}

/*
@ 将两个链表都打印出来，用于调试
@ 返回值: 无
*/
void printLists()
{
	puts("g_idleCardList有如下元素（第一个是表长）:");
	ListPrint(&g_idleCardList);
	puts("g_usredCardList有如下元素（第一个是表长）:");
	ListPrint(&g_usredCardList);
}
/*
@ 初始化所有卡信息
@ 返回值: 无
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
@ 开卡，分配卡号和卡信息
@ 入参：enCard,卡类型; charge: 充值
@ 出参: cardNo, 分配的卡号
@ 返回值: EN_RETURN_SUCC，分配成功; EN_RETURN_CARD_OVERLOW, 分配失败;
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
@ 充值
@ 入参：cardNo,卡号; recharge: 充值
@ 出参: 无
@ 返回值: EN_RETURN_SUCC，成功; 其他, 失败;
*/
EN_RETURN_CODE RechargeCard(unsigned int cardNo, unsigned int recharge)
{
    
    return EN_RETURN_SUCC;
}

/*
@ 获取卡余额
@ 入参：cardNo,卡号; 
@ 出参: balance: 余额
        enCard:  卡类型
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INVALID_CARD, 失败;
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
@ 卡扣费
@ 入参：cardNo,卡号; enCard, 卡类型; deductPrice, 扣费票价
@ 出参: balance, 扣费后的余额
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INVALID_CARD, EN_RETURN_BALANCE_NOT_ENOUGH, 失败;
*/
EN_RETURN_CODE DeductCard(unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int deductPrice, unsigned int &balance)
{
    return EN_RETURN_SUCC;
}

/*
@ 删除卡信息
@ 入参：cardNo,卡号; 
@ 出参: 无
@ 返回值: 0，成功; -1, 失败;
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
@ 获取卡类型字符串
@ 入参：enCard,卡类型; 
@ 出参: 无
@ 返回值: 卡类型字符串;
*/
char* GetCardTypeStr(EN_CARD_TYPE enCard)
{
	char* ret;
	switch(enCard){
	    case(EN_CARD_TYPE_SINGLE):
			ret="单程卡";
			break;
		case(EN_CARD_TYPE_ELDER):
			ret="老年卡";
			break;
		case(EN_CARD_TYPE_NOMAL):
			ret="普通卡";
			break;
		default:
			ret="unknown";
	}
    return ret;
}

/*
@ 根据卡类型字符串, 识别卡类型
@ 入参：cardType,      卡类型字符串; 
@ 出参: enCard,        卡类型
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INPUT_INVALID_CARDTYPE, 失败;
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