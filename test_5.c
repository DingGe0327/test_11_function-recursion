#define  _CRT_SECURE_NO_WARNINGS 1
//求第n个斐波那契数
//1 1 2 3 5 8 13 21 34 55...
#include <stdio.h>
int Fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = Fib(n);
	printf("%d\n", sum);
	return 0;
}
















