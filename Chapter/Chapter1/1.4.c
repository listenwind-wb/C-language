#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define		LOWER	0
#define		UPPER	300
#define		STEP	20

int main()
{
	//1·ûºÅ³£Á¿
	int fahr;


	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));


	return 0;
}