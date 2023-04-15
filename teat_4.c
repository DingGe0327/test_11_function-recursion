#define  _CRT_SECURE_NO_WARNINGS 1
//求n的阶乘，不考虑栈溢出
#include <stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	int mul = 1;
	//迭代
	for (i = 1; i <= n; i++)
	{
		mul = mul * i;
	}
	printf("%d\n", mul);
	return 0;
  }


#include <stdio.h>
int Fun(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Fun(n - 1);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int mul = Fun(n);

	printf("%d\n", mul);
	return 0;
}













