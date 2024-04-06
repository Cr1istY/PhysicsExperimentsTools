#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Main.h"






//float GetAverage(float P[], int n);


//int main()
//{
//	int P[4] = { 1,1,1,1 };
//	printf("%f", GetAverage(P, 4));
//	return 0;
//}
/*线性回归求斜率
*****注意数据类型
*参数   count         数据个数 数组行(列)的个数 数组的行列数目相等
*参数   dataCol_X[]   数据的列数据
*参数   dataRow_Y[]   数据的行数据
*返回值 k             斜率 范围(-∞,∞)
*本算法定义斜率为 ∞ 的情况 k = 0;
*使用注意 需要重定义数据类型
*typedef unsigned char  uint8;
*typedef unsigned int   uint16;
*typedef unsigned long  uint32;
*/



int main(void)
{
	int choose = 1;
	float T, T2;
	
	printf("请输入室温(摄氏度)：");
	scanf("%f", &T2);
	printf("室温为：%.1f\n", T2);
	T = T2 + 273.0;
	while (4 != choose)
	{
		printf("\n请输入你要所计算的数据类型\n表一:同一温度下，测量气体的压强与体积的关系(1)\n表二:同一体积下，测量气体的压强与温度的关系(2)\n表三:同一压强下，测量气体的体积与温度的关系(3)\n----------------\n\t退出(4)\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Tab1(T);
			break;
		case 2:
			Tab2();
			break;
		case 3:
			Tab3();
			break;
		case 4:
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}


		/*
		if (1 == choose) Tab1(T);
		else if (2 == choose) Tab2();
		else if (3 == choose) Tab3();
		else if (4 == choose) break;
		else
		{
			printf("输入错误，请重新输入");
		}
		*/
	}
	printf("已退出");
	return 0;
}


