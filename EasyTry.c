#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



void Tab1(float T);
void Tab2();
void Tab3();
void GetV();
void GetT();
void GetT2();
typedef float uint8;
typedef float uint16;
typedef float uint32;



float get_K(uint8 count, uint8 dataCol_X[], uint8 dataRow_Y[])
{
	float k = 0;//斜率
	float aveCol_X = 0;//列的平均值x
	float aveRow_Y = 0;//行的平均值y
	uint16 sum_XY = 0;//行列的总和xy
	uint16 sumRow_Y = 0;//行的总和y
	uint16 sumCol_X = 0;//列的总和x
	uint32 sumCol_X2 = 0;//列的总和x^2

	for (int i = 0; i < count; i++)
	{
		sumCol_X += dataCol_X[i];//求列x的总和
		sumRow_Y += dataRow_Y[i];//求行y的总和
		sumCol_X2 += dataCol_X[i] * dataCol_X[i];//求x^2的总和
		sum_XY += (dataCol_X[i] * dataRow_Y[i]);//求xy的总和
	}

	aveCol_X = (float)sumCol_X / count;//求平均值
	aveRow_Y = (float)sumRow_Y / count;

	if (sumCol_X2 - aveCol_X * aveCol_X * count)
	{
		k = (sum_XY - aveCol_X * aveRow_Y * count) / //根据公式求斜率
			(sumCol_X2 - aveCol_X * aveCol_X * count);
	}
	//斜率为∞的情况 定义斜率等于0
	else
		k = 0;

	return k;
}


//计算表一，用指针；
void Tab1(float T)
{
	float v[7] = { 0.06,0.07,0.08,0.09,0.1,0.11,0.12 };
	int i, t[7];
	float P[7];
	float P2[7];
	float k, n;
	printf("表一:同一温度下，测量气体的压强与体积的关系\nV:\n");
	GetV();
	printf("时\n请输入对应压强（kPa）:\n");
	for (i = 0; i <= 6; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("存为%.1f\n", P[i]);
	}
	printf("计算结果如下：\n1/p(kPaE-1)\n");
	for (i = 0; i <= 6; i++)
	{
		printf("%e\t", 1 / P[i]);
		P2[i] = 1 / P[i];
	}
	k = 0.06 / (P2[6] - P2[0]);
	n = k / (T * 8.314);
	printf("\nk = %f\nn = %f\n", k, n);
	printf("计算完成");
}


void Tab2()
{
	int i;
	float P[6];
	//float P2[7];
	float T[6] = { 313, 323, 333, 343, 353, 363 };
	float k, n, R, dR;
	printf("表二:同一体积下，测量气体的压强与温度的关系\n");
	printf("请输入表一所求出的 n 值：");
	scanf("%f", &n);
	GetT();
	printf("时\n请输入对应压强（kPa）:\n");
	for (i = 0; i <= 5; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("存为%.1f\n", P[i]);
	}
	k = 50 / (P[5] - P[0]);
	R = k * 90.0 / n;
	dR = R - 8.314;
	printf("\nk:%.1f\tR:%.3f\tdR:%.3f\n", k, R, dR);
	printf("计算完成");
}

void Tab3()
{
	int i;
	float P[6];
	float k, n, P1, dR, R;
	float T[6] = { 313, 323, 333, 343, 353, 363 };
	printf("表三：同一压强下，测量气体的体积与温度的关系\n");
	printf("请输入表一所求出的 n 值：");
	scanf("%f", &n);
	printf("请输入表一体积为90ml时压强P：");
	scanf("%f", &P1);
	GetT2();
	printf("时\n请输入对应体积:\n");
	for (i = 0; i <= 5; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("存为%.1f\n", P[i]);
	}
	k = 50 / (P[5] - P[0]);
	R = k * P1 / n;
	dR = R - 8.314;
	printf("\nk:%.1f\tR:%.3f\tdR:%.3f\n", k, R, dR);
	printf("计算完成");
}



void GetV()
{
	int V;
	printf("当气体体积分别为：");
	for (V = 60; V <= 120; V = V + 10)
	{
		printf("%d.0\t", V);
	}
}

void GetT()
{
	int T;
	printf("当气体温度分别为：");
	for (T = 40; T <= 90; T = T + 10)
	{
		printf("%d.0\t", T);
	}
}

void GetT2()
{
	int T;
	printf("当气体温度分别为：");
	for (T = 90; T >= 40; T = T - 10)
	{
		printf("%d.0", T);
	}
}

