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
	//MessageBox(NULL, TEXT("�����Թ�ͼ�����������󴰿ڣ��򽫴�����󻯡�"), TEXT("��ʾ"), 0);
	Game_Init();
	while (1)
	{
		ch = _getch();//��ȡ�û�����
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