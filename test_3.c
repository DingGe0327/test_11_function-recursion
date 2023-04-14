#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int my_strlen(char* str)//数组名相当于数组首元素的地址
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = { "abc" };
	
	printf("%d\n", my_strlen(arr));//编写一个函数，模拟strlen
	return 0;
}
 

//编写一个函数，不允许创建临时变量，求字符串长度
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("")    1+1+1++0=3
#include <stdio.h>
#include <string.h>
int my_strlen(char* str)//数组名相当于数组首元素的地址
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char arr[] = { "abc" };

	printf("%d\n", my_strlen(arr));//编写一个函数，模拟strlen
	return 0;
}






















