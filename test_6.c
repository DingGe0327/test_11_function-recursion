#define  _CRT_SECURE_NO_WARNINGS 1
//дһ���ݹ麯��������һ��Ǹ��������������ǵĺ�
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



















