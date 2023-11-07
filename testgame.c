
#include "game1.h"


void game()
{	
	char ret;
	char arr[ROW][COL]={0};
	Initarr(arr,ROW,COL);//初始化函数为空格 
	Displayarr(arr,ROW,COL);//展示棋盘
	while(1)
	{
		playermove(arr,ROW,COL);//玩家下棋 
		Displayarr(arr,ROW,COL);
		ret=Iswin(arr,ROW,COL);
		if (ret!='c')
			break;
		computermove(arr,ROW,COL);//电脑下棋 
		Displayarr(arr,ROW,COL);
		if (ret!='c')
			break;
	}
	if (ret=='*')
		printf("游戏结束，玩家获胜！:)");
	else if (ret=='#')
		printf("游戏结束，电脑获胜:("); 
	else if (ret=='d')
		printf("游戏结束，平局-----") ;
}


void menu()
{
	printf("********************************\n");
	printf("********1.play     2.exit*******\n");
	printf("********************************\n");
}



void test()
{
	srand((unsigned int) time(0));
	menu();
	int a;
error:
	printf("请输入：");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default :
			printf("输入错误，请重新输入\n");
			goto error;
			break;
			
	
	
	}
}

int main() 
{
	test();
	return 0;
}
