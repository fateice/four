#ifndef __SUBWAY_GLOBAL_H__
#define __SUBWAY_GLOBAL_H__
//Socketͨ�Ž��պͷ��ͻ�����󳤶�
#define MAX_RECEIVE_BUFFER_LENGTH 1024
#define MAX_SEND_BUFFER_LENGTH 1024
#include "subwayCard/subwayCard.h"
//����ϵͳʱ��
typedef struct
{
    int hour;
    int minutes;
}ST_SUBWAY_TIME;
typedef struct STR_CARD
{
    EN_CARD_TYPE enCard;	//������
    unsigned int cardNo;    //����
    bool usrFlag;           //���Ƿ�����
    unsigned int balance;//kje
    //TListHead list;			//����ṹ
}ST_SUBWAY_CARD;
//ST_SUBWAY_CARD g_cardList[MAX_CARD_NUM];
//TListHead* g_idleCardList;    //˫���������еĿ�
//TListHead* g_usredCardList;   //˫������ʹ���еĿ�
#endif