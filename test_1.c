#define  _CRT_SECURE_NO_WARNINGS 1
//����ݹ�
//#include <stdio.h>
//int main()
//{
//	printf("hh");
//	main();
//	return 0;
//}

//����һ������ֵ���޷��ţ�����˳���ӡ��ÿһλ
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
	scanf("%u", &num);    //%u�޷�������
	print(num);             //���壺print�������Դ�ӡ������ÿһλ
	return 0;
}

























