#ifndef __SUBWAY_GLOBAL_H__
#define __SUBWAY_GLOBAL_H__

//Socket通信接收和发送缓存最大长度
#define MAX_RECEIVE_BUFFER_LENGTH 1024
#define MAX_SEND_BUFFER_LENGTH 1024

//地铁系统时间
typedef struct
{
    int hour;
    int minutes;
}ST_SUBWAY_TIME;

typedef struct STR_CARD
{
    EN_CARD_TYPE enCard;  //卡类型
    unsigned int cardNo;       //卡号
    bool usrFlag;             //卡是否启用
    unsigned int balance;       //卡余额
    TListHead list; //链表结构
}ST_SUBWAY_CARD;

ST_SUBWAY_CARD g_cardList[MAX_CARD_NUM];  //所有卡信息
TListHead g_idleCardList;    //双向链表：空闲的卡
TListHead g_usredCardList;   //双向链表：使用中的卡
#endif