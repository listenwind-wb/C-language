#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TAB_SIZE 8
int pos = 0;

int main()
{
	char arr[1000];
	int i = 0;
	int c = 0;

	while ((c = getchar()) != EOF && i < 1000)
	{
		arr[i] = (char)c;
		i++;
	}

	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (arr[j] == '\t')
		{
			for (c = 0; c < (TAB_SIZE - (pos % TAB_SIZE)); c++)
			{
				putchar(' ');
			}
			pos = 0;
		}
		else if (arr[j] == '\n')
		{
			putchar('\n');
			pos = 0;
		}
		else
		{
			putchar(arr[j]);
			pos++;
			if (pos == TAB_SIZE)
				pos = 0;
		}
	}

	return 0;
}