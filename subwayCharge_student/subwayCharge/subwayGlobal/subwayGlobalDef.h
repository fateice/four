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
#endif