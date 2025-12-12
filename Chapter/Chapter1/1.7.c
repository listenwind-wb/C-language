#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

float change(float m);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = change(fahr);
		printf("%3.0f\t%7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}













	return 0;
}

float change(float fahr)
{
	return 5.0 * (fahr - 32.0) / 9.0;

}