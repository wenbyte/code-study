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

//��һ�������洢�ڶ�������1�ĸ���
//int main()
//{
//	int s = 0;
//	int a;
//	scanf("%d",&a);
//	for (int i = 0; i < 32; i++)
//		if (1 == (1 & (a >> i)))
//			s += 1;
//
//	//�޷����㸺��
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

//���õ���������������������
//int main()
//{
////��ӷ�
//	int a = 1;
//	int b = 3;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//���
//	int a = 1;
//	int b = 3;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d%d",a, b);
//	return 0;
//}