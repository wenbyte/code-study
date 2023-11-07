#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define COL 9
#define ROW 9
#define COLS COL+2
#define ROWS ROW+2
#define NUM 10
char mine[ROWS][COLS] = { '0' };
char show[ROWS][COLS] = { '0' };
//初始化数组
void initboard(char mine[ROWS][COLS], int row, int col, char set)
{
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			mine[i][j] = set;
	}
}
//打印数组	
void Displaymine(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= COL; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
			printf("%c ", mine[i][j]);
		printf("\n");
	}
	printf("\n");
}


//设置炸弹
void Setmine(char mine[ROWS][COLS], int row, int col,int n)
{

	
	while (n)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			n--;
		}
	}

}

//找周围地雷的数目
int  Countnum(char mine[ROWS][COLS], int x, int y)
{
	int a,b;
	int s = 0;
	for (a=x-1;a<=x+1 ; a++)
	{
		for (b = y-1; b <= y+1; b++)
		{
			if (a>= 1 && a <= ROW && b>= 1 && b <= COL)

			{
				s = mine[a][b] - '0' + s;
			}
		}
	}
	return s;

}

void Linkshow(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	if (Countnum(mine, x, y) == 0)
	{
		show[x][y] = '0';
		int a, b;
		int s = 0;
		for (a = x - 1; a <= x + 1; a++)
		{
			for (b = y - 1; b <= y + 1; b++)
			{
				if (a >= 1 && a <= ROW && b >= 1 && b <= COL)
				{
					if (show[a][b] == '*' )
						Linkshow(mine, show, ROW, COL, a, b);
				}

			}
		}
	}
	else
		show[x][y] = '0' + Countnum(mine, x, y);

}

//找地雷
int Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int step = 1;
	Displaymine(show, ROW, COL);
while (1)
{

	printf("***************************\n");
	printf("******1.检查   2.标记******\n");
	printf("***************************\n");
	printf("请输入：");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
	{	
		system("cls");
		Displaymine(show, ROW, COL);
		int x, y;
	printf("请输入要检查的坐标：\n");
	printf("x=");
	scanf("%d", &x);
	printf("y=");
	scanf("%d", &y);
	
	if (step == 1 && mine[x][y] == '1')//第一次不踩雷
	{
		mine[x][y] = '0';
		Setmine(mine, ROW, COL, 1);
		
	}
	else
	{
		step += 1;
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL && show[x][y] == '*')//坐标合法且还没走过
		{
			if (mine[x][y] == '1')//是地雷
			{
				printf("踩到地雷了！ :(\n");
				printf("地雷图：\n");
				Displaymine(mine, ROW, COL);
				return 0;
			}
			else if (mine[x][y] == '0')
			{
				show[x][y] = '0' + Countnum(mine, ROW, COL, x, y);//显示该点周围的雷数
				Linkshow(mine, show, ROW, COL, x, y);
				system("cls");
				Displaymine(show, COL, ROW);

			}
		}

		else
			printf("输入错误，请重新输入！\n");
		//检查是否结束
		int i, j;
		int n = 0;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] != '*' && show[i][j] != '#')
					n += 1;
			}
		}
		if (n == COL * ROW - NUM)
		{
			printf("排雷成功！:)\n");
			return 0;
		}
	}//不是第一次循环
	break;
	}//case1

	case 2:
	{while (1)
	{
		int x, y;
		printf("请输入要检查的坐标：\n");
		printf("x=");
		scanf("%d", &x);
		printf("y=");
		scanf("%d", &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL && show[x][y] == '*')
		{
			if (show[x][y] == '*')
			{
				show[x][y] = '#';
				system("cls");
				Displaymine(show, ROW, COL);
				break;
			}
		}
		else
			printf("输入错误，请重新输入！\n");
	}
	}
	default :
		system("cls");
		Displaymine(show, ROW, COL);
		printf("输入错误，请重新输入！\n");
	}
}
return 0;
}





void game()
{	
	initboard(mine, ROW, COL, '0');
	initboard(show, ROW, COL, '*');
	Setmine(mine, ROW, COL,NUM);
	Findmine(mine,show,ROW, COL);

}	


void menu()
{	
	printf("***************************\n");
	printf("******1.play   0.exit******\n");
	printf("***************************\n");
}


void test()
{
	
	int a;
	do
	{
		srand((unsigned int)time(0));
		menu();
		printf("请选择：\n");
		scanf("%d",&a);
		getchar();
		system("cls");
		switch (a)
		{case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (a);
}


int main()
{
	test();
	return 0;
}