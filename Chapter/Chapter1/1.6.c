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
#define	 ML    20

void print_table1(int lword[], int ml)
{
	int i, j;
	i = j = 0;

	for (i = 0; i < ml; i++)
	{
		printf("%d\t", i + 1);
		for (j = 0; j < lword[i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

void print_table2(int lword[], int ml)
{
	int i, j, max;
	max = lword[0];
	for (i = 1; i < ml; i++)
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
			for (k = 0; k < ml; k++)
			{
				printf("\t%d", k + 1);
			}
			break;
		}
		for (j = 0; j < ml; j++)
		{
			printf("\t");
			if (lword[j] >= max - i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}

int main()
{
	//1.1
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;
	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			nwhite++;
		else
			nother++;
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
		nwhite, nother);

	//1.2
	int c, wl, state, i;
	wl = 0;
	state = OUT;
	int lword[ML];
	for (i = 0; i < ML; i++)
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
	print_table1(lword, ML);
	print_table2(lword, ML);


















	return 0;
}