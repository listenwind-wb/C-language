#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define	OUT	0
#define IN  1

int main()
{
	int c = 0;
	int state = OUT;
	int count = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t' || c == ',')
		{
			if (state == IN)
			{
				state = OUT;
				printf("\n");
			}
		}
		else if (state == OUT)
		{
			state = IN;
			count = 0;
		}
		if (state == IN)
		{
			putchar(c);
		}
	}

	

	








	return 0;
}