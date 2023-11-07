#include<stdio.h>
#include<graphics.h>
//鼠标画线
//int main()
//{
//	initgraph(600,600);
//	bool p = false;
//	int x, y;
//	while(1)
//	{ 
//	ExMessage msg;
//	peekmessage(&msg,EM_MOUSE);
//	if (msg.message == WM_LBUTTONDOWN)
//	{
//		x = msg.x;
//		y = msg.y;
//		p = true;
//	}
//	if (msg.message == WM_LBUTTONUP)
//		p = false;
//	if (p == true && msg.message == WM_MOUSEMOVE)
//	{
//		setlinecolor(RED);
//		setlinestyle(PS_SOLID,10);
//		line(x, y, msg.x, msg.y);
//	}
//	x = msg.x;
//	y = msg.y;
//	if (msg.message == WM_LBUTTONUP)
//		cleardevice();
//	}
//	return 0;
//}


//鼠标点击
//int main()
//{
//	initgraph(600, 600);
//
//	while (1)
//	{
//		ExMessage m;
//		peekmessage(&m, EM_MOUSE);
//		if (m.message == WM_LBUTTONDOWN)
//			circle(m.x, m.y, 5);
//	}
//	system("pause");
//	return 0;
//
//}