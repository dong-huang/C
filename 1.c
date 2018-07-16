#include "stdio.h"
#include "string.h"

int main()
{
	//1
	char input[100];
	scanf("%s", input);
	//2
	int a = 0, b = 0, div = 0;
	for (; div < strlen(input);div++)
	if(input[div]=='/')
		break;
	for (int i = 0; i < div;i++)
		a = a * 10 + input[i] - '0';
	for (int i = div + 1; i < strlen(input);i++)
		b = b * 10 + input[i] - '0';
	//3
	int inte = a / b;
	if(inte)
		printf("%d.", inte);
	else
		printf(".");



	int d = a % b;
	int pobeh[100];
	pobeh[1] = d;
	pobeh[0] = -1;
	for (int i = 2; i < 100;i++)
		pobeh[i] = pobeh[i - 1] * 10 % b;
	int cnt = 2, begin = 0;
	for (;;cnt++)
	{
		if((begin=check(pobeh,pobeh[cnt],cnt))!=-1)
		{
			cnt--;
			break;
		}
	}
	//
	for (int i = 1; i < begin;i++)
		printf("%d", pobeh[i] * 10 / b);
	if(pobeh[begin]==0)
		return 0;
		else {
			printf("(");
			for (int i = begin; i <= cnt;i++)
				printf("%d", pobeh[i] * 10 / b);
			printf(")");
		}
		return 0;
}
int check(int a[], int b, int c)
{
	for (int i = 1; i < c;i++)
	if(b==a[i]){
		return i;
	}
	return -1;
}