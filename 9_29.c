#include<stdio.h> 
//青蛙跳到第n台阶有几种可能   一次跳一阶或两阶
//int pp(int n)
//{
//	if(n<=11)
//		return 1;
//	else
//	{
//		return pp(n-1)+pp(n-2); 
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int m=pp(n);
//	printf("%d",m); 
//	return 0;
//} 

	 


//求第n个斐波那契数
//int ff(int a)  //递归 
//{
//	if (a<=2)
//		return 1;
//	else
//		return ff(a-1)+ff(a-2);
//}
//int ff1(int a)//迭代 
//{
//	int b=1;
//	int n=3;
//	int i=1;
//	int j=1;
//	while (a>2)
//	{
//					
//		b=i+j;
//		a--;
//		j=i;
//		i=b;
//	}
//	return b;
//		
//} 
//int main()
//{
//	int a,b ;
//	printf("请输入你要找的位数：");
//	scanf("%d",&a);
//	b=ff1(a);
//	printf("%d",b);
//	return 0;
//} 
