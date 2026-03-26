#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	//01
	char a = 5;
	//00000000 00000000 00000000 00000101
	//00000101 - a
	char b = 126;
	//00000000 00000000 00000000 01111110
	//011111110 -b

	char c = a + b;
	//00000000 00000000 00000000 00000101 - a
	//00000000 00000000 00000000 01111110 - b
	//00000000 00000000 00000000 10000101 - a+b
	//10000011 - c

	printf("%d\n", c);
	//11111111 11111111 11111111 10000011 - 补码(整形提升后的c)
	//11111111 11111111 11111111 10000010 - 反码
	//10000000 00000000 00000000 01111101 - 源码 (-125)

	//02
	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;

	if (a == 0xb6)
	{
		printf("a");
	}

	if (b == 0xb600)
	{
		printf("b");
	}

	if (c == 0xb6000000)
	{
		printf("c");
	}

	//03
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(-c));

	//04
	int a = 1;
	int b = (++a) + (++a) + (++a);
	printf("%d\n", b);








	return 0;
}