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
	//1for”Ôæ‰
	int fahr;


	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	//2
	int fahr;


	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
















	return 0;
}