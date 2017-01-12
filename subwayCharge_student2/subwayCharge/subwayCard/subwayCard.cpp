#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;


/*
@ 初始化所有卡信息
@ 返回值: 无
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
	cardNo=1;
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