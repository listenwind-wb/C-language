#define _CRT_SECURE_NO_WARNINGS  // 消除VS中scanf等函数的安全警告
#include <stdio.h>               // 标准输入输出头文件
#include <stdlib.h>              // 内存管理等函数头文件
#include <time.h>                // 时间相关函数（本代码未使用）
#include <windows.h>            // Windows系统函数（本代码未使用）
#include <string.h>             // 字符串操作函数头文件
#include <math.h>               // 数学函数头文件（如abs、max）
#include <stdbool.h>            // 布尔类型支持头文件



int main()
{
	//07
	int arr[3][4] = { {1,2},{5,6},{9,1,9} };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			if (arr[i][j] == 9)
				arr[i][j] = 10;
			printf("%2d ", arr[i][j]);

		}
		printf("\n");
	}




















	return 0;
}










