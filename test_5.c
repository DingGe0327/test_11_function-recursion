#define  _CRT_SECURE_NO_WARNINGS 1
//���n��쳲�������
//1 1 2 3 5 8 13 21 34 55...
#include <stdio.h>  //�ݹ�
int count = 0;
int Fib(int n)
{
	if (n == 3)
	{
		count++;  //�ݹ�Ч�ʺܵ�
	}
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
	//int count = 0;  //����д�����Ҫд����������
	scanf("%d", &n);
	int sum = Fib(n);
	printf("%d\n", sum);
	printf("%d\n", count);
	return 0;
}

#include <stdio.h>  //ѭ��
int count = 0;
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;

		a = b;
		b = c;     //��������˳��һ�����ܴ�
		n--;
		count++;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	printf("%d\n", count);
	return 0;
}














