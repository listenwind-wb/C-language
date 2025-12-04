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

void InitArray(char Array[COU][CH], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			Array[i][j] = '\0';
	}
}

int main()
{
	int c;
	int MC = 0;     //不同字符个数
	char StatisticsChar[COU][CH];
	InitArray(StatisticsChar, COU, CH);

	while ((c = getchar()) != EOF)
	{
		if (IsSame(StatisticsChar, COU, CH, c))
		{
			MC++;
			StatisticsChar[0][MC - 1] = c;
			StatisticsChar[1][MC - 1] = 1;
		}





	}





	return 0;
}