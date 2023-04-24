#define  _CRT_SECURE_NO_WARNINGS 1
//编写一个函数实现k的n次方（递归）
#include <stdio.h>
double Power(int i, int k)
{
	if (k == 0)
	{
		return 1.0;
	}
	else if (k > 0)
	{
		return Power(i, k - 1) * i;
	}
	else
	{
		//return 1.0 / ((Power(i, -k - 1)) * i);  
		return 1.0 / (Power(i, -k));
	}
}
int main()
{
	int i = 2;
	int k = -3;
	double mul = Power(i,k);
	printf("%lf\n", mul);
	return 0;
}















