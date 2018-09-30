#include "game_maze.h"

Game_maze game_maze;
void Game_Init()
{
	game_maze.x_new = 1;
	game_maze.y_new = 1;
	game_maze.x_old = 1;
	game_maze.y_old = 1;
	game_maze.isover = false;
	game_maze.map_choose = 0;
	Draw_Page();
}

void gotoxy(int x, int y)
{
	//句柄 ：标志应用程序中的不同对象和同类对象中的不同的实例 方便操控
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出的句柄 <windows.h>
	COORD pos = { x, y };	 //定义一个字符在控制台屏幕上的坐标POS
	SetConsoleCursorPosition(hConsole, pos);	//定位光标位置的函数<windows.h>
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Draw_Page()
{
	int i, j;
	system("cls");
	for (i = 0;i < M;i++)
	{
		for (j = 0;j < N;j++)
		{
			if (map[game_maze.map_choose][i][j] == 1)//砖块
				printf("█");
			else if (map[game_maze.map_choose][i][j] == 0 && (i == game_maze.x_new) && (j == game_maze.y_new))//小人当前位置
				printf("人");
			else if (map[game_maze.map_choose][i][j] == 8)//终点标志
				printf("★");
			else
				printf("  ");//通道
		}
		printf("\n");
	}
	gotoxy(test_x, 6);
	printf("A-Left ");
	gotoxy(test_x, 7);
	printf("D-Right");
	gotoxy(test_x, 8);
	printf("W-Up   ");
	gotoxy(test_x, 9);
	printf("S-Down ");
	gotoxy(test_x, 10);
	printf("Q-Quit ");
	HideCursor();
}

void Draw_man()
{
	gotoxy(2 * game_maze.x_old, game_maze.y_old);
	printf("  ");//去除移动前的小人
	gotoxy(2 * game_maze.x_new, game_maze.y_new);
	printf("人");//画移动后的
	game_maze.x_old = game_maze.x_new;//画完小人之后更新小人坐标
	game_maze.y_old = game_maze.y_new;
}

void move(char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
	{
		if ((!game_maze.isover) && game_maze.y_new > 0 && map[game_maze.map_choose][game_maze.y_new - 1][game_maze.x_new] != 1)//上边界
		{
			game_maze.y_new = game_maze.y_new - 1;
		}
		Draw_man();
		isover();
		break;
	}
	case 'a':
	case 'A':
	{
		if ((!game_maze.isover) && game_maze.x_new > 0 && map[game_maze.map_choose][game_maze.y_new][game_maze.x_new - 1] != 1)//不在左边界，并且左边无砖块
		{
			game_maze.x_new = game_maze.x_new - 1;
		}
		Draw_man();
		isover();
		break;
	}
	case 's':
	case 'S':
	{
		if ((!game_maze.isover) && game_maze.y_new < N - 1 && map[game_maze.map_choose][game_maze.y_new + 1][game_maze.x_new] != 1)//下边界
		{
			game_maze.y_new = game_maze.y_new + 1;
		}
		Draw_man();
		isover();
		break;
	}
	case 'd':
	case 'D':
	{
		if ((!game_maze.isover) && game_maze.x_new < M - 1 && map[game_maze.map_choose][game_maze.y_new][game_maze.x_new + 1] != 1)//右边界
		{
			game_maze.x_new = game_maze.x_new + 1;
		}
		isover();
		Draw_man();
		break;
	}
	case 'y':
	case 'Y':
	{
		if (game_maze.isover)//上一次游戏已经结束
		{
			if (game_maze.map_choose < 2)//地图还没用完
			{
				game_maze.isover = false;
				game_maze.map_choose++;
				game_maze.x_new = 1;
				game_maze.y_new = 1;
				game_maze.x_old = 1;
				game_maze.y_old = 1;
				Draw_Page();
			}
			else
			{
				system("cls");
				gotoxy(0, 0);
				printf("Congratulation you pass all the Maze！！！");
			}
		}
	}
	break;
	case 'n':
	case 'N':
	{
		if (game_maze.isover)//上一次游戏已经结束
		{
			system("cls");
			gotoxy(0, 0);
			printf("Thanks for Playing!");
		}
	}
	break;
	default:
		break;
	}
}

void isover()//小人坐标（x，y）
{
	//主要数组的x，y和屏幕的不一样
	if (map[game_maze.map_choose][game_maze.y_new][game_maze.x_new] == 8)
	{
		game_maze.isover = true;
		gotoxy(test_x, 13);
		printf("You Win！！!");
		gotoxy(test_x, 14);
		printf("Next Map? (y —— yes,n —— no)");
	}
}
