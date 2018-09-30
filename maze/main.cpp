#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include "game_maze.h"




int main()
{
	char ch;
	//MessageBox(NULL, TEXT("由于迷宫图过大，请先拉大窗口，或将窗口最大化。"), TEXT("提示"), 0);
	Game_Init();
	while (1)
	{
		ch = _getch();//获取用户输入
		if (ch == 'q' || ch == 'Q')
		{
			break;
		}
		else
		{
			move(ch);
		}
	}
	system("cls");
	gotoxy(0, 0);
	printf("Thanks for Playing!\n");
}