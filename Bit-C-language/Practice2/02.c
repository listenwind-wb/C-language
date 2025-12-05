#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse(char* str)
{
	char tmp = *str;
	int len = my_strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (my_strlen(str + 1) >= 2)
		reverse(str + 1);
	*(str + len - 1) = tmp;
}

int DigitSum(int n)
{
	if (n > 9)
		return DigitSum(n / 10) + n % 10;
}

double Pow(int n, int k)
{
	if (k > 0)
		return n * Pow(n, k - 1);
	else if (k == 0)
		return 1;
	else
		return 1.0 / Pow(n, -k);
}

int main()
{
	//01.1
	char arr[] = "abcdef"; //[a b c d e f \0]
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 2;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;

		left++;
		right--;
	}
	printf("%s\n", arr);

	//01.2
	char arr[] = "abcdefg"; //[a b c d e f g \0]
	reverse(arr);
	printf("%s\n", arr);

	//02
	unsigned int n = 0;
	scanf("%u", &n);
	int sum = DigitSum(n);
	printf("%d\n", sum);

	//03
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double ret = Pow(n, k);
	printf("%lf\n", ret);







	return 0;
}