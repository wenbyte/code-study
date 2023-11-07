#include<stdio.h>
////冒泡排序
//int main()
//{
//	int i=0;
//	
//	int tmp=0;
//	int j=0;
//	int a[]={1,9,4,5,7,2};
//	int sz=sizeof(a)/sizeof(a[0]);
//	for(i=0;i<sz-1;i++)
//	{	int flag=1;
//		for (j=0;j<sz-1-i;j++)
//		{	
//			if (a[j]>a[j+1])
//			{	
//				tmp=a[j];
//				a[j]=a[j+1];
//				a[j+1]=tmp;
//				flag=-1	; 		
//			}
//		}
//		if (flag==1)
//			break;
//		
//	}
//	for(i=0;i<sz;i++)
//		printf("%d ",a[i]);
//	return 0;
//} 


//int main()
//{
//	int a[10]={1,'2',3};
//	printf("%c",'2');
//	return 0;
//}

//汉诺塔 n个板子所需要的次数 与过程 
//void hh(int n,char a,char b,char c)
//{	
//	if(n==1)
//	{	
//		printf("%c-->%c\n",a,c);
//		
//	}
//	else
//	{
//		hh(n-1,a,c,b);
//		printf("%c-->%c\n",a,c);
//		hh(n-1,b,a,c);
//		
//	}
//	
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	hh(n,'a','b','c'); 
//
//	return 0;
//} 
