#include "stdafx.h"
#include <iostream>
#include  <sstream>
#include "subwayMacro.h"
#include "include/basePrice.h"
using namespace std;

/*
@ ��ȡ����Ʊ��, ������վ�����վ��֮��������̷ּ�����
@ -1, ��ѯ����Ʊ��ʧ��; ����, ����Ʊ��
*/
int GetBasePrice(unsigned int meters)
{
    if(meters>0&&meters<=3)
		return 2;
	else if(meters>3&&meters<=5)
		return 3;
	else if(meters>5&&meters<=10)
		return 4;
	else if(meters>10)
		return 5;
	else
		return -1;
}