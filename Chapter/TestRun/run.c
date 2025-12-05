#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define	 CH    100         //字符
#define  COU   2         //计次

void InitArray(char Array[COU][CH], int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < col; j++)
			Array[i][j] = '\0';
	}
	for (i = 1; i < 2; i++)
	{
		for (j = 0; j < col; j++)
			Array[i][j] = 0;
	}
}

int IsSame(char StatisticsChar[COU][CH], int col, int c, int mc)
{
	int i = 0;
	for (i = 0; i < mc; i++)
	{
		if (c == StatisticsChar[0][i])
			return i;
	}
	return -1;
}

void print_char_table1(char Array[COU][CH], int mc)
{
	int i, j;
	int row = mc;
	for (i = 0; i < mc; i++)
	{
		printf("%c\t", Array[0][i]);
		for (j = 0; j < Array[1][i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}
int main()
{
	int c;
	int mc = 0;     //不同字符个数
	char StatisticsChar[COU][CH];
	InitArray(StatisticsChar, CH);

	while ((c = getchar()) != EOF)
	{
		if (IsSame(StatisticsChar, CH, c, mc) == -1)
		{
			if (c != '\t' && c != ' ' && c != '\n')
			{
				mc++;
				StatisticsChar[0][mc - 1] = c;
				StatisticsChar[1][mc - 1] = 1;
			}
		}
		else
		{
			StatisticsChar[1][IsSame(StatisticsChar, CH, c, mc)]++;
		}
	}
	print_char_table1(StatisticsChar, mc);

	




	return 0;
}