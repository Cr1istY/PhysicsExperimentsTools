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
	float k = 0;//б��
	float aveCol_X = 0;//�е�ƽ��ֵx
	float aveRow_Y = 0;//�е�ƽ��ֵy
	uint16 sum_XY = 0;//���е��ܺ�xy
	uint16 sumRow_Y = 0;//�е��ܺ�y
	uint16 sumCol_X = 0;//�е��ܺ�x
	uint32 sumCol_X2 = 0;//�е��ܺ�x^2

	for (int i = 0; i < count; i++)
	{
		sumCol_X += dataCol_X[i];//����x���ܺ�
		sumRow_Y += dataRow_Y[i];//����y���ܺ�
		sumCol_X2 += dataCol_X[i] * dataCol_X[i];//��x^2���ܺ�
		sum_XY += (dataCol_X[i] * dataRow_Y[i]);//��xy���ܺ�
	}

	aveCol_X = (float)sumCol_X / count;//��ƽ��ֵ
	aveRow_Y = (float)sumRow_Y / count;

	if (sumCol_X2 - aveCol_X * aveCol_X * count)
	{
		k = (sum_XY - aveCol_X * aveRow_Y * count) / //���ݹ�ʽ��б��
			(sumCol_X2 - aveCol_X * aveCol_X * count);
	}
	//б��Ϊ�޵���� ����б�ʵ���0
	else
		k = 0;

	return k;
}


//�����һ����ָ�룻
void Tab1(float T)
{
	float v[7] = { 0.06,0.07,0.08,0.09,0.1,0.11,0.12 };
	int i, t[7];
	float P[7];
	float P2[7];
	float k, n;
	printf("��һ:ͬһ�¶��£����������ѹǿ������Ĺ�ϵ\nV:\n");
	GetV();
	printf("ʱ\n�������Ӧѹǿ��kPa��:\n");
	for (i = 0; i <= 6; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("��Ϊ%.1f\n", P[i]);
	}
	printf("���������£�\n1/p(kPaE-1)\n");
	for (i = 0; i <= 6; i++)
	{
		printf("%e\t", 1 / P[i]);
		P2[i] = 1 / P[i];
	}
	k = 0.06 / (P2[6] - P2[0]);
	n = k / (T * 8.314);
	printf("\nk = %f\nn = %f\n", k, n);
	printf("�������");
}


void Tab2()
{
	int i;
	float P[6];
	//float P2[7];
	float T[6] = { 313, 323, 333, 343, 353, 363 };
	float k, n, R, dR;
	printf("���:ͬһ����£����������ѹǿ���¶ȵĹ�ϵ\n");
	printf("�������һ������� n ֵ��");
	scanf("%f", &n);
	GetT();
	printf("ʱ\n�������Ӧѹǿ��kPa��:\n");
	for (i = 0; i <= 5; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("��Ϊ%.1f\n", P[i]);
	}
	k = 50 / (P[5] - P[0]);
	R = k * 90.0 / n;
	dR = R - 8.314;
	printf("\nk:%.1f\tR:%.3f\tdR:%.3f\n", k, R, dR);
	printf("�������");
}

void Tab3()
{
	int i;
	float P[6];
	float k, n, P1, dR, R;
	float T[6] = { 313, 323, 333, 343, 353, 363 };
	printf("������ͬһѹǿ�£����������������¶ȵĹ�ϵ\n");
	printf("�������һ������� n ֵ��");
	scanf("%f", &n);
	printf("�������һ���Ϊ90mlʱѹǿP��");
	scanf("%f", &P1);
	GetT2();
	printf("ʱ\n�������Ӧ���:\n");
	for (i = 0; i <= 5; i++)
	{
		scanf("%f", &P[i]);
		//getch();
		printf("��Ϊ%.1f\n", P[i]);
	}
	k = 50 / (P[5] - P[0]);
	R = k * P1 / n;
	dR = R - 8.314;
	printf("\nk:%.1f\tR:%.3f\tdR:%.3f\n", k, R, dR);
	printf("�������");
}



void GetV()
{
	int V;
	printf("����������ֱ�Ϊ��");
	for (V = 60; V <= 120; V = V + 10)
	{
		printf("%d.0\t", V);
	}
}

void GetT()
{
	int T;
	printf("�������¶ȷֱ�Ϊ��");
	for (T = 40; T <= 90; T = T + 10)
	{
		printf("%d.0\t", T);
	}
}

void GetT2()
{
	int T;
	printf("�������¶ȷֱ�Ϊ��");
	for (T = 90; T >= 40; T = T - 10)
	{
		printf("%d.0", T);
	}
}

