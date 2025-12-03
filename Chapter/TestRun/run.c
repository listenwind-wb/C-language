#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define  IN    1
#define  OUT   0

void print_table1(int lword[])
{
	int i, j;
	i = j = 0;

	for (i = 0; i < 15; i++)
	{
		printf("%d\t", i + 1);
		for (j = 0; j < lword[i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

void print_table2(int lword[])
{
	int i, j, max;
	max = lword[0];
	for (i = 1; i < 15; i++)
	{
		if (max < lword[i])
		{
			max = lword[i];
		}
	}
	int row = max + 1;
	for (i = 0; i < row; i++)
	{
		if (i == row - 1)
		{
			int k = 0;
			for (k = 0; k < 15; k++)
			{
				printf("\t%d", k + 1);
			}
			break;
		}			
		for (j = 0; j < 15; j++)
		{
			printf("\t");
			if (lword[j] >= max - i)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	





}

int main()
{
	int c, wl, state, i;
	wl = 0;
	state = OUT;
	int lword[15];
	for (i = 0; i < 15; i++)
		lword[i] = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == IN)
			{
				lword[wl - 1]++;
				state = OUT;
				wl = 0;
			}
		}
		else
		{
			state = IN;
			wl++;
		}
	}
	//print_table1(lword);
	print_table2(lword);


	

	








	return 0;
}