#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//��������
//void BGM()
//{	
//	mciSendString(L"open 2.mp3 ",0,0,0);
//	mciSendString(L"play 2.mp3", 0, 0, 0);
//
//
//}
//�ı䴰�����ƺ���ʾѡ��С����
void change()
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, L"w shi da shuai ge");
	MessageBox(hnd, L"��ϲ���н������", L"��ʾ", MB_OKCANCEL);
}
int main()
{
	initgraph(600, 600,SHOWCONSOLE);//��������	
	//BGM();
	change();
	setbkcolor(WHITE);
	cleardevice();//���ñ���ɫ

	//����
	/*setfillcolor(BLACK);
	solidrectangle(0, 190, 600, 200);
	solidrectangle(0, 390, 600, 400);
	solidrectangle(190, 0, 200, 600);
	solidrectangle(390, 0, 400, 600);*/


	//��Բ
	//setlinecolor(BLUE);//���û�����ɫ
	//setlinestyle(PS_SOLID, 4);
	//setfillcolor(BLACK);//���������ɫ
	//circle(50, 50, 50);            //����Բ
	//fillcircle(150, 150, 50);	   //�б߿��Բ
	//solidcircle(250, 250, 50);     //�ޱ߿�Բ

	//��������
	//settextcolor(RGB(189,183,255));
	//settextstyle(50, 0,L"����");
	//setbkmode(TRANSPARENT);
	//outtextxy(0, 0, L"��ѧeasyxͼ��");
	

	//����ͼƬ
	//IMAGE img;
	//loadimage(&img, L"tupian/bg.png");
	//putimage(0, 0, &img);


	//��������
	//int x = 0, y = 0;
	//
	//while (1)
	//{	
	//	BeginBatchDraw();
	//	//����ͼƬ
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