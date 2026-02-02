#define _CRT_SECURE_NO_WARNINGS
#include "game2.h"



void menu()
{
	printf("*************************\n");
	printf("*******  1.play  ********\n");
	printf("*******  0.exit  ********\n");
}


void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷区
	char show[ROWS][COLS] = { 0 };//存放排查的雷区









}



int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	

	return 0;

}
