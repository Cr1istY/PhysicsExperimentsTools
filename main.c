#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h> //����log����
#include<string.h> //������ģ��
#include<windows.h> //������ģ��


//����lnRx �� 1/T ��ֵ
void proc() //������
{
	int i = 0;
	char buf[102];
	memset(buf, '\0', sizeof(buf));
	const char* lable = "|/-\\";
	while (i <= 100) {
		printf("[%-101s][%d%%][%c]\r", buf, i, lable[i % 4]);
		fflush(stdout);
		buf[i] = '=';
		i++;
		Sleep(1.5);//���ٶȣ���Ȼ����̫С�ǻ�Ҫɶ��������
	}
	printf("\n");
} //

int main()
{
	int T = 40;
	float R = 0, Rd;
	float Result[10];
	printf("���������������ֵ:\n���������������Fn\n");
	printf("�¶ȣ�\t");
	for (T = 40; T <= 75; T = T + 5)
	{
		printf("%7d", T);
	}
	int m = 0;
	T = 40;
	while (m <= 7)
	{
		printf("\n�������¶�Ϊ %d ʱ��Rֵ:", T);
		scanf("%f", &R);
		printf("�ѱ���RֵΪ��%.1f",R);
		Rd = log(R);
		Result[m] = Rd;
		m++;
		T = T + 5;
	}
	printf("\n");
	proc(); //����������
	printf("\n�������,�������:\nR:\n");
	int i;
	for (i = 0; i <= 7; i++)
	{
		printf("%f\t", Result[i]);
		if (i == 7)
		{
			printf("\n1/T:\n");
			for (T = 40; T <= 75; T = T + 5)
			{
				printf("%f\t", 1.0 / (T + 273));
			}
		}
	}
	float B, A;
	B = (Result[0] - Result[1]) / ((1.0 / (40 + 273)) - (1.0 / (45 + 273)));
	A = Result[0] * exp(-1 * (B / (40 + 273)));
	printf("\nB = %f\nA = %f\n",B,A);
	return 0;
}