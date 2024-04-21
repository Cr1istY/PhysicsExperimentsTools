#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//typedef struct XValue {
//
//
//
//}XValue;


typedef struct power {
	//千分尺偏差
	float delt;
	
	float d[6];
	//平均直径
	float d1;
	//H(mm)
	float H;
	//D(mm)
	float D;
	//L(mm)
	float L;
	//拉力视值
	float m[10];
	//加力时标尺刻度
	float x1[10];
	//减力时刻度
	float x2[10];
	//平均
	float x3[10];
	//该变量(5 个单位)
	float x4[5];
	float dx;
}power;

void input(power* X)
{
	int i;
	//float xiValue = 0;
	float value = 0;
	printf("请输入偏差值:");
	scanf("%f", &X->delt);
	printf("\n请输入直径:");
	for (i = 0; i <= 5; i++)
	{
		scanf("%f", &X->d[i]);
		value += X->d[i];
	}
	X->d1 = X->delt + (value / 6);
	printf("H:");
	scanf("%f", &X->H);
	printf("D:");
	scanf("%f", &X->D);
	printf("L:");
	scanf("%f", &X->L);
	for (i = 0; i <= 9; i++)
	{
		X->m[i] = (float) i;
		printf("输入(%.2f)加力和减力(x+ x-)时标尺刻度：\n",X->m[i]);
		scanf("%f %f", &X->x1[i], &X->x2[i]);
		printf("\nsaved\n");
	}
}

void output(power* X)
{
	
	int i = 0;
	float value = 0;
	for (i = 0; i <= 9; i++)
	{
		X->x3[i] = (X->x1[i] + X->x2[i]) / 2;
	}
	for (i = 0; i <= 4; i++)
	{
		X->x4[i] = X->x3[i + 5] - X->x3[i];
		value += X->x4[i];
	}
	X->dx = value / 5;
	printf("Xi : ");
	for (i = 0; i <= 9; i++)
	{
		printf("%.2f ", X->x3[i]);
	}
	printf("\ndX : ");
	for (i = 0; i <= 4; i++)
	{
		printf("%.2f ", X->x4[i]);
	}
	printf("\n");
	printf("平均dx = %.2f", X->dx);
	printf("d = %,2f", X->d1);
}

float GetE(power* X)
{
	float E1;
	float E2;
	float E;
	E1 = 8 * 5.0 * 9.8 * X->L * X->H;
	E2 = 3.13 * X->d1 * X->d1 * X->D * X->dx;
	E = E1 / E2;
	printf("\nE : %.3f", E);
}


int main(void)
{
	power X;
	input(&X);
	output(&X);
	GetE(&X);

}