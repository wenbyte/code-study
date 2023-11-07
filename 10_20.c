#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	printf("%d",sizeof(short));
	return 0;
}

//int main()
//{
//	int a = -2 % 2;	
//	printf("%d",a);
//	return 0;
//}

//求一个整数存储在二进制中1的个数
//int main()
//{
//	int s = 0;
//	int a;
//	scanf("%d",&a);
//	for (int i = 0; i < 32; i++)
//		if (1 == (1 & (a >> i)))
//			s += 1;
//
//	//无法计算负数
//	/*int a = 3;
//	while(a)
//	{
//		
//		s += a % 2;
//		a = a / 2;
//	}*/
//	printf("%d",s);
//	return 0;
//}

//不用第三个变量交换两个变量
//int main()
//{
////相加法
//	int a = 1;
//	int b = 3;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//异或法
//	int a = 1;
//	int b = 3;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d%d",a, b);
//	return 0;
//}