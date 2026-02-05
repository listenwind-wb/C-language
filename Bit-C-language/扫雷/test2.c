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
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');//mine 数组在没有布置雷的时候全部用'0'表示
	InitBoard(show, ROWS, COLS, '*');//show 数组在没有布置雷的时候全部用*表示

	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);

	/*DisplayBoard(mine, ROW, COL);*/


	//排查雷
	FindMine(mine, show, ROW, COL);
}



int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
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
