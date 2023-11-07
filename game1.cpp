#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址


int map[3][3];
int arr[8][3][2] =
{ {{0,0},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{2,0},{2,1},{2,2}},
	{{0,0},{1,0},{2,0}},
	{{0,1},{1,1},{2,1}},
	{{0,2},{1,2},{2,2}},
	{{0,0},{1,1},{2,2}},
	{{0,2},{1,1},{2,0}},

};
IMAGE bg,gou,cha,win,defeat,pj;
//初始化窗口
void initgame()
{
	initgraph(600, 600);//窗口大小
	loadimage(&bg, L"tupian/bg.png");     //600*600
	loadimage(&gou, L"tupian/gou-3.png");//140*140
	loadimage(&cha, L"tupian/cha-2.png");//140*140
	loadimage(&win, L"tupian/win.png");
	loadimage(&defeat, L"tupian/defeat.png");
	loadimage(&pj, L"tupian/pg.png");
	putimage(0,0, &bg);

}
//人下棋
void mango(MOUSEMSG* m,int map[3][3])
{
	int x = (m->x)/200; 
	int y = (m->y)/200;

	putimage(30 + x * 200, 30 + y * 200, &gou);
	map[y][x] = 1;   //对于数组来说第一项是y  第二项是x   人落子


	
	
}

//检验对面是否快赢了
int checkwin(int map[3][3])
{
	int s = 0;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		s = 0;
		for (j = 0; j < 3; j++)
		{
			s += map[arr[i][j][1]][arr[i][j][0]];

		}
		if (s == -2)//ai要赢了
		{
			int a;
			for (a = 0; a < 3; a++)
			{
				if (map[arr[i][a][1]][arr[i][a][0]] == 0)
				{
					map[arr[i][a][1]][arr[i][a][0]] = -1;
					putimage(30 + arr[i][a][0] * 200, 30 + arr[i][a][1] * 200, &cha);
					
					printf("自己赢\n");
					int m, n;
					printf("ai\n");
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
							printf("%d", map[m][n]);
						printf("\n");
					}
					return 1;
				}
			}


		}
	}
	for (i = 0; i < 8; i++)
	{
		s = 0;
		for (j = 0; j < 3; j++)
		{
			s += map[arr[i][j][1]][arr[i][j][0]];

		}
		
		if (s == 2)//这个情况下对面要赢了
		{
			int a;
			for (a = 0; a < 3; a++)
			{
				if (map[arr[i][a][1]][arr[i][a][0]] == 0)
				{
					map[arr[i][a][1]][arr[i][a][0]] = -1;
					putimage(30 + arr[i][a][0] * 200, 30 + arr[i][a][1] * 200, &cha);
					printf("对面赢\n");
					int m, n;
					printf("ai\n");
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
							printf("%d", map[m][n]);
						printf("\n");
					}
					return 1;
				}
				
			}
		}
		
	}
	return 0;
}
//ai下棋
int aigo(int map[3][3])
{
	
	int i, j;
	if (checkwin(map))
		return 0;//让自己赢 和不让别人赢
	if (map[1][1] != 0)//中心给下了
	{
		
		
		for (i = 0; i < 3; i = i + 2)//找四个角
		{
			for (j = 0; j < 3; j = j + 2)
			{

				if (map[i][j] == 0)//如果还没下
				{

					map[i][j] = -1;
					putimage(30 + j * 200, 30 + i * 200, &cha);
					printf("四个角");
					int m, n;
					printf("ai\n");
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
							printf("%d", map[m][n]);
						printf("\n");
					}
					return 0;//若四个角有空 则下在四个角上
				}
			}
		}
		int x = rand() % 3;
		int y = rand() % 3;
		while (map[y][x] != 0)
		{
			x = rand() % 3;
			y = rand() % 3;
		}
		map[y][x] = -1;
		putimage(30 + x * 200, 30 + y * 200, &cha);
		printf("随机\n");
		int m, n;
		printf("ai\n");
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
				printf("%d", map[m][n]);
			printf("\n");
		}
		return 0;//随机下

	}
	else if (map[1][1] == 0)
	{
		map[1][1] = -1;
		putimage(30 + 200, 30 + 200, &cha);
		printf("中间\n");
		int m, n;
		printf("ai\n");
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
				printf("%d", map[m][n]);
			printf("\n");
		}
		return 0;//下中间
	}

	return 0;
	
	
 	
}

int check(int map[3][3])
{
	int s = 0;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		s = 0;
		for (j = 0; j < 3; j++)
		{
			s += map[arr[i][j][1]][arr[i][j][0]];

		}
		if (s == 3)
		{
			Sleep(1000);
			putimage(0, 0, &win);
			Sleep(10000);
			return 1;
		}
		if (s == -3)
		{
			Sleep(1000);
			putimage(0, 0, &defeat);
			Sleep(10000);
			return 1;

		}


	}//检查获胜
	int n = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (map[i][j] != 0)
				n++;
		}
	}
	if (n == 9)
	{
		putimage(0, 0, &pj);
		Sleep(10000);
		return 1;
	}//检查平局
	return 0;


}

int main()
{
	int map[3][3] = { {0,0,0},{0,0,0},{0,0,0} };  //存放棋子的数组
	MOUSEMSG m;
	srand((unsigned int)time(NULL)); //生成随机数
	initgame();
	srand((unsigned int)time(0));
	while (1)
	{
		
		m = GetMouseMsg();//得到鼠标数据
		if (m.uMsg == WM_LBUTTONDOWN && map[m.y/200][m.x/200]==0)// 当按下鼠标左键且该点没有棋子
		{	
			
			mango(&m,map);//人走
			if (check(map))
				break;
		
			aigo(map);//ai走
			if (check(map))
				break;
		}
	}
	
	//MessageBox(NULL, L"Hello", L"Notice", NULL);//出去黑框

	
	return 0;
}