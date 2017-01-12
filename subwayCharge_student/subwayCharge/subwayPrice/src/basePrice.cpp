#include "stdafx.h"
#include <iostream>
#include  <sstream>
#include "subwayMacro.h"
#include "include/basePrice.h"
using namespace std;

/*
@ 获取基础票价, 即按进站点与出站点之间的最短里程分级计算
@ -1, 查询基础票价失败; 其他, 基础票价
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