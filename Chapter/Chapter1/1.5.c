#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define	IN	1
#define OUT	0

int main()
{
	//1.1ÎÄ¼þ¸´ÖÆ
	int c = 0;

	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}

	//1.2
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}

	//1.3
	int c;

	while (c = getchar() != EOF)
	{
		printf("%d\n", c);
	}


	//2.1
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);

	//2.2
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);

	//3.1
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);

	//3.2
	int c, nl, nt, nb;

	nl = nt = nb = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++nb;
		else if (c == '\n')
			++nl;
		else if (c == '\t')
			++nt;

	printf("nb = %d\nnt = %d\nnl = %d", nb, nt, nl);

	//3.3
	int c;
	int nb = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nb;
		else if (c != '\t')
			nb = 0;
		if (nb > 1)
		{
			continue;
		}
		if (c == '\t')
		{
			putchar(' ');
			++nb;
			continue;
		}
		putchar(c);
	}

	//3.4
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}

	//4.1
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("nl = %d , nw = %d , nc = %d\n", nl, nw, nc);

	//4.2
	int c = 0;
	int state = OUT;
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
		}
		if (state == IN)
		{
			putchar(c);
		}
	}







	return 0;
}