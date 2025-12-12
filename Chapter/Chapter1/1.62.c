#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define	 MAX    256         


int IsSame(char char_storage[MAX], int mc, int c)
{
	int i = 0;
	for (i = 0; i < mc; i++)
	{
		if (c == char_storage[i])
			return i;
	}
	return -1;
}

void print_char_table1(char char_storage[MAX], int digit_storage[MAX], int mc)
{
	int i, j;
	int row = mc;
	for (i = 0; i < mc; i++)
	{
		if (char_storage[i] == ' ')
			printf("空格\t");
		else if (char_storage[i] == '\t')
			printf("\\t\t");
		else if (char_storage[i] == '\n')
			printf("\\n\t");
		else
			printf("%c\t", char_storage[i]);
		for (j = 0; j < digit_storage[i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main(void)
{
    //01
    int c;
    int counts[256] = { 0 };
    int i;

    while ((c = getchar()) != EOF)
    {
        counts[(unsigned char)c]++;
    }

    /* 打印所有出现过的字符 */
    for (i = 0; i < 256; i++) {
        if (counts[i] == 0) continue;
        if (i == ' ')
            printf("空格\t");
        else if (i == '\t')
            printf("\\t\t");
        else if (i == '\n')
            printf("\\n\t");
        else
            printf("%c\t", (char)i);

        for (int j = 0; j < counts[i]; j++)
            printf("* ");
        printf("\n");
    }


    //02
	int c;
	int mc = 0;     //不同字符个数
	char char_storage[MAX];
	int  digit_storage[MAX];
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		char_storage[i] = '\0';
	}
	for (j = 0; j < MAX; j++)
	{
		digit_storage[j] = 0;
	}


	while ((c = getchar()) != EOF)
	{
		int tmp = IsSame(char_storage, mc, c);
		if (tmp == -1)
		{
			mc++;
			char_storage[mc - 1] = c;
			digit_storage[mc - 1] = 1;
		}
		else
		{
			digit_storage[tmp]++;
		}
	}
	print_char_table1(char_storage, digit_storage, mc);












    return 0;
}
