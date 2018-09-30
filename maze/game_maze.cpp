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
	//��� ����־Ӧ�ó����еĲ�ͬ�����ͬ������еĲ�ͬ��ʵ�� ����ٿ�
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ��׼����ľ�� <windows.h>
	COORD pos = { x, y };	 //����һ���ַ��ڿ���̨��Ļ�ϵ�����POS
	SetConsoleCursorPosition(hConsole, pos);	//��λ���λ�õĺ���<windows.h>
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
			if (map[game_maze.map_choose][i][j] == 1)//ש��
				printf("��");
			else if (map[game_maze.map_choose][i][j] == 0 && (i == game_maze.x_new) && (j == game_maze.y_new))//С�˵�ǰλ��
				printf("��");
			else if (map[game_maze.map_choose][i][j] == 8)//�յ��־
				printf("��");
			else
				printf("  ");//ͨ��
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
	printf("  ");//ȥ���ƶ�ǰ��С��
	gotoxy(2 * game_maze.x_new, game_maze.y_new);
	printf("��");//���ƶ����
	game_maze.x_old = game_maze.x_new;//����С��֮�����С������
	game_maze.y_old = game_maze.y_new;
}

void move(char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
	{
		if ((!game_maze.isover) && game_maze.y_new > 0 && map[game_maze.map_choose][game_maze.y_new - 1][game_maze.x_new] != 1)//�ϱ߽�
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
		if ((!game_maze.isover) && game_maze.x_new > 0 && map[game_maze.map_choose][game_maze.y_new][game_maze.x_new - 1] != 1)//������߽磬���������ש��
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
		if ((!game_maze.isover) && game_maze.y_new < N - 1 && map[game_maze.map_choose][game_maze.y_new + 1][game_maze.x_new] != 1)//�±߽�
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
		if ((!game_maze.isover) && game_maze.x_new < M - 1 && map[game_maze.map_choose][game_maze.y_new][game_maze.x_new + 1] != 1)//�ұ߽�
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
		if (game_maze.isover)//��һ����Ϸ�Ѿ�����
		{
			if (game_maze.map_choose < 2)//��ͼ��û����
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
				printf("Congratulation you pass all the Maze������");
			}
		}
	}
	break;
	case 'n':
	case 'N':
	{
		if (game_maze.isover)//��һ����Ϸ�Ѿ�����
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

void isover()//С�����꣨x��y��
{
	//��Ҫ�����x��y����Ļ�Ĳ�һ��
	if (map[game_maze.map_choose][game_maze.y_new][game_maze.x_new] == 8)
	{
		game_maze.isover = true;
		gotoxy(test_x, 13);
		printf("You Win����!");
		gotoxy(test_x, 14);
		printf("Next Map? (y ���� yes,n ���� no)");
	}
}
