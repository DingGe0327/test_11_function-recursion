#define  _CRT_SECURE_NO_WARNINGS 1
//错误递归
//#include <stdio.h>
//int main()
//{
//	printf("hh");
//	main();
//	return 0;
//}

//接收一个整形值（无符号），按顺序打印出每一位
#include <stdio.h>
void print(unsigned int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	unsigned int num = 0;
	scanf("%u", &num);    //%u无符号整形
	print(num);             //定义：print函数可以打印参数的每一位
	return 0;
}

























