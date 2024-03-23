#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h> //引用log函数
#include<string.h> //进度条模块
#include<windows.h> //进度条模块


//计算lnRx 及 1/T 的值
void proc() //进度条
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
		Sleep(1.5);//改速度，当然，改太小那还要啥进度条阿
	}
	printf("\n");
} //

int main()
{
	int T = 40;
	float R = 0, Rd;
	float Result[10];
	printf("请输入热敏电阻的值:\n若输入完成请输入Fn\n");
	printf("温度：\t");
	for (T = 40; T <= 75; T = T + 5)
	{
		printf("%7d", T);
	}
	int m = 0;
	T = 40;
	while (m <= 7)
	{
		printf("\n请输入温度为 %d 时的R值:", T);
		scanf("%f", &R);
		printf("已保存R值为：%.1f",R);
		Rd = log(R);
		Result[m] = Rd;
		m++;
		T = T + 5;
	}
	printf("\n");
	proc(); //进度条引用
	printf("\n计算完成,结果如下:\nR:\n");
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