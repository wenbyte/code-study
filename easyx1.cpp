#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//播放音乐
//void BGM()
//{	
//	mciSendString(L"open 2.mp3 ",0,0,0);
//	mciSendString(L"play 2.mp3", 0, 0, 0);
//
//
//}
//改变窗口名称和显示选择小窗口
void change()
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, L"w shi da shuai ge");
	MessageBox(hnd, L"恭喜你中奖五百万！", L"提示", MB_OKCANCEL);
}
int main()
{
	initgraph(600, 600,SHOWCONSOLE);//创建窗口	
	//BGM();
	change();
	setbkcolor(WHITE);
	cleardevice();//设置背景色

	//画井
	/*setfillcolor(BLACK);
	solidrectangle(0, 190, 600, 200);
	solidrectangle(0, 390, 600, 400);
	solidrectangle(190, 0, 200, 600);
	solidrectangle(390, 0, 400, 600);*/


	//画圆
	//setlinecolor(BLUE);//设置画线颜色
	//setlinestyle(PS_SOLID, 4);
	//setfillcolor(BLACK);//设置填充颜色
	//circle(50, 50, 50);            //空心圆
	//fillcircle(150, 150, 50);	   //有边框的圆
	//solidcircle(250, 250, 50);     //无边框圆

	//绘制文字
	//settextcolor(RGB(189,183,255));
	//settextstyle(50, 0,L"楷体");
	//setbkmode(TRANSPARENT);
	//outtextxy(0, 0, L"初学easyx图形");
	

	//加载图片
	//IMAGE img;
	//loadimage(&img, L"tupian/bg.png");
	//putimage(0, 0, &img);


	//键盘输入
	//int x = 0, y = 0;
	//
	//while (1)
	//{	
	//	BeginBatchDraw();
	//	//加载图片
	//	IMAGE img;
	//	loadimage(&img, L"tupian/bg.png");
	//	putimage(0, 0, &img);
	//	setfillcolor(RED);
	//	solidcircle(x, y, 50);
	//	FlushBatchDraw();
	//	if (GetAsyncKeyState(VK_UP))
	//		y -= 1;
	//	if (GetAsyncKeyState(VK_DOWN))
	//		y += 1;
	//	if (GetAsyncKeyState(VK_RIGHT))
	//		x += 1;
	//	if (GetAsyncKeyState(VK_LEFT))
	//		x -= 1;
	//	

	//}
	
	
	getchar();
	closegraph();
	return 0;
}