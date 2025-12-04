#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	//01
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











	return 0;
}