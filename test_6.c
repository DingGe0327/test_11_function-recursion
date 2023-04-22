#define  _CRT_SECURE_NO_WARNINGS 1
//写一个递归函数，输入一组非负整数，返回它们的和
#include <stdio.h>
int Bigsum(int n)
{
	if (n > 9)
	{
		return Bigsum(n / 10) + n % 10;
	}
	else
	{
		return n;
	}
}
int main()
{
	int num = 1111;
	int sum = Bigsum(num);
	printf("%d\n", sum);  //4
	return 0;
}



















