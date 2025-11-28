#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//数组传参的时候，形参有两种写法：int arr[] 或 int* arr     数组or指针
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	}
}

int count = 0;
int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;

	while (n >= 3)
	{
		count++;
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int Fib(int n)
{
	count++;                              //此时用嵌套函数不好,建议用Fib1
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}

int my_strlen1(char* str)
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

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void print(unsigned int x)
{
	if (x > 9)
	{
		print(x / 10);
	}
	printf("%d ", x % 10);
}

int main()
{
	//01嵌套调用函数
	int len = strlen("abcdef");
	printf("%d\n", len);
	printf("%d\n", strlen("abcdef"));
	printf("%d ", printf("%d ", printf("%d ", 43)));

	//02函数声明
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int Add(int x, int y);    //函数声明
	int sum = Add(a, b);
	printf("%d\n", sum);

	//03函数递归 [递  归]
	unsigned int num = 0;
	scanf("%u", &num);
	print(num);            //接受一个无符号整形，并按顺序打印它的每一位


	char arr[] = "abc";
	int ret = my_strlen(arr);
	printf("%d\n", ret);

	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	printf("%d\n", count);

	int n = 0;
	scanf("%d", &n);
	int ret = Fib1(n);
	printf("%d\n", ret);
	printf("%d\n", count);

	//04.数组创建
	int arr[20];
	char ch[5];
	double data1[10];
	double data2[15 + 5];

	//05.数组初始化
	int arr9[10] = { 1,2,3 };
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	char ch1[3] = { 'a','b','c' };
	char ch2[] = "abc";
	char ch3[] = "abcdef";
	printf("%s\n", ch2);

	//06.数组元素地址
	int arr[] = { 1,2,3,4,5,6,7,8,9,20 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("arr[%d] = %p\n", i, &arr[i]);
	}

	//07.二维数组的创建与初始化
	int arr[3][4] = { {1,2},{5,6},{9,1} };
	int arr1[][4] = { {1,23,4},{5,6} };
	int arr2[2][2] = { 1,2,3,4 };
	char arr3[5][10];

	//08.二维数组元素的地址
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
			printf("arr[%d][%d] = %p\n", i, j, &arr[i][j]);
	}

	//09.数组的越界访问
	int arr[] = { 1,2,3,4,5,6 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	
	int arr[] = { 1,2,3,4,5,6 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);            //可一定程度上避免越界
	for (i = 0; i < sz; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,21 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j <= 4; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
	}

	//10.数组传参——冒泡排序
	int arr[] = { 4,5,2,7,5,2,5,53,757,42,48 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}























	return 0;
}

int Add(int x, int y)
{
	return x + y;
}
