#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // ������ڵ�ַ


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
//��ʼ������
void initgame()
{
	initgraph(600, 600);//���ڴ�С
	loadimage(&bg, L"tupian/bg.png");     //600*600
	loadimage(&gou, L"tupian/gou-3.png");//140*140
	loadimage(&cha, L"tupian/cha-2.png");//140*140
	loadimage(&win, L"tupian/win.png");
	loadimage(&defeat, L"tupian/defeat.png");
	loadimage(&pj, L"tupian/pg.png");
	putimage(0,0, &bg);

}
//������
void mango(MOUSEMSG* m,int map[3][3])
{
	int x = (m->x)/200; 
	int y = (m->y)/200;

	putimage(30 + x * 200, 30 + y * 200, &gou);
	map[y][x] = 1;   //����������˵��һ����y  �ڶ�����x   ������


	
	
}

//��������Ƿ��Ӯ��
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
		if (s == -2)//aiҪӮ��
		{
			int a;
			for (a = 0; a < 3; a++)
			{
				if (map[arr[i][a][1]][arr[i][a][0]] == 0)
				{
					map[arr[i][a][1]][arr[i][a][0]] = -1;
					putimage(30 + arr[i][a][0] * 200, 30 + arr[i][a][1] * 200, &cha);
					
					printf("�Լ�Ӯ\n");
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
		
		if (s == 2)//�������¶���ҪӮ��
		{
			int a;
			for (a = 0; a < 3; a++)
			{
				if (map[arr[i][a][1]][arr[i][a][0]] == 0)
				{
					map[arr[i][a][1]][arr[i][a][0]] = -1;
					putimage(30 + arr[i][a][0] * 200, 30 + arr[i][a][1] * 200, &cha);
					printf("����Ӯ\n");
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
//ai����
int aigo(int map[3][3])
{
	
	int i, j;
	if (checkwin(map))
		return 0;//���Լ�Ӯ �Ͳ��ñ���Ӯ
	if (map[1][1] != 0)//���ĸ�����
	{
		
		
		for (i = 0; i < 3; i = i + 2)//���ĸ���
		{
			for (j = 0; j < 3; j = j + 2)
			{

				if (map[i][j] == 0)//�����û��
				{

					map[i][j] = -1;
					putimage(30 + j * 200, 30 + i * 200, &cha);
					printf("�ĸ���");
					int m, n;
					printf("ai\n");
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
							printf("%d", map[m][n]);
						printf("\n");
					}
					return 0;//���ĸ����п� �������ĸ�����
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
		printf("���\n");
		int m, n;
		printf("ai\n");
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
				printf("%d", map[m][n]);
			printf("\n");
		}
		return 0;//�����

	}
	else if (map[1][1] == 0)
	{
		map[1][1] = -1;
		putimage(30 + 200, 30 + 200, &cha);
		printf("�м�\n");
		int m, n;
		printf("ai\n");
		for (m = 0; m < 3; m++)
		{
			for (n = 0; n < 3; n++)
				printf("%d", map[m][n]);
			printf("\n");
		}
		return 0;//���м�
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


	}//����ʤ
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
	}//���ƽ��
	return 0;


}

int main()
{
	int map[3][3] = { {0,0,0},{0,0,0},{0,0,0} };  //������ӵ�����
	MOUSEMSG m;
	srand((unsigned int)time(NULL)); //���������
	initgame();
	srand((unsigned int)time(0));
	while (1)
	{
		
		m = GetMouseMsg();//�õ��������
		if (m.uMsg == WM_LBUTTONDOWN && map[m.y/200][m.x/200]==0)// �������������Ҹõ�û������
		{	
			
			mango(&m,map);//����
			if (check(map))
				break;
		
			aigo(map);//ai��
			if (check(map))
				break;
		}
	}
	
	//MessageBox(NULL, L"Hello", L"Notice", NULL);//��ȥ�ڿ�

	
	return 0;
}