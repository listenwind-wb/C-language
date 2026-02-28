#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int main()
{
	char s[] = "1234";
	printf("%d\n", atoi(s));
	char s2 = -1;
	int a = s2;
	printf("%d\n", a);






















	return 0;
}

