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
/*���Իع���б��
*****ע����������
*����   count         ���ݸ��� ������(��)�ĸ��� �����������Ŀ���
*����   dataCol_X[]   ���ݵ�������
*����   dataRow_Y[]   ���ݵ�������
*����ֵ k             б�� ��Χ(-��,��)
*���㷨����б��Ϊ �� ����� k = 0;
*ʹ��ע�� ��Ҫ�ض�����������
*typedef unsigned char  uint8;
*typedef unsigned int   uint16;
*typedef unsigned long  uint32;
*/



int main(void)
{
	int choose = 1;
	float T, T2;
	
	printf("����������(���϶�)��");
	scanf("%f", &T2);
	printf("����Ϊ��%.1f\n", T2);
	T = T2 + 273.0;
	while (4 != choose)
	{
		printf("\n��������Ҫ���������������\n��һ:ͬһ�¶��£����������ѹǿ������Ĺ�ϵ(1)\n���:ͬһ����£����������ѹǿ���¶ȵĹ�ϵ(2)\n����:ͬһѹǿ�£����������������¶ȵĹ�ϵ(3)\n----------------\n\t�˳�(4)\n");
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
			printf("�����������������");
			break;
		}


		/*
		if (1 == choose) Tab1(T);
		else if (2 == choose) Tab2();
		else if (3 == choose) Tab3();
		else if (4 == choose) break;
		else
		{
			printf("�����������������");
		}
		*/
	}
	printf("���˳�");
	return 0;
}


