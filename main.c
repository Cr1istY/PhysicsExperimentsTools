#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//typedef struct XValue {
//
//
//
//}XValue;


typedef struct power {
	//ǧ�ֳ�ƫ��
	float delt;
	
	float d[6];
	//ƽ��ֱ��
	float d1;
	//H(mm)
	float H;
	//D(mm)
	float D;
	//L(mm)
	float L;
	//������ֵ
	float m[10];
	//����ʱ��߿̶�
	float x1[10];
	//����ʱ�̶�
	float x2[10];
	//ƽ��
	float x3[10];
	//�ñ���(5 ����λ)
	float x4[5];
	float dx;
}power;

void input(power* X)
{
	int i;
	//float xiValue = 0;
	float value = 0;
	printf("������ƫ��ֵ:");
	scanf("%f", &X->delt);
	printf("\n������ֱ��:");
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
		printf("����(%.2f)�����ͼ���(x+ x-)ʱ��߿̶ȣ�\n",X->m[i]);
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
	printf("ƽ��dx = %.2f", X->dx);
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