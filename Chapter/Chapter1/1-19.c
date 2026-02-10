#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reverse(char s[])
{
	int i = 0;
	int j = 0;
	while (s[j] != '\0')
		j++;
	for (i = 0, j = j - 1; i < j; i++, j--)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main()
{
	while (1)
	{
		char arr[1000];
		int i = 0;
		int c = 0;
		while ((c = getchar()) != EOF && c != '\n' && i < 999)
		{
			arr[i] = (char)c;
			i++;
		}
		arr[i] = '\0';
		reverse(arr);
		printf("%s\n", arr);
		if (c == EOF)
			break;
	}
	return 0;
}