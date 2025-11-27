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
	//1.1.1ÎÄ¼þ¸´ÖÆ
	int c = 0;

	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}

	//1.1.2
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}

	//1.1.3
	int c;

	while (c = getchar() != EOF)
	{
		printf("%d\n", c);
	}


	//1.2.1
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);

	//1.2.2
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);








	return 0;
}