#include<stdio.h>
#include<string.h>
#include<math.h>
//���ֲ��Һ���
//int find(int a[],int b,int sz)
//{
//	int i=0;
//	int j=sz-1;
//	while(i<=j)
//	{
//		int mid=(i+j)/2;
//		if(a[mid]<b)
//			i=mid+1;
//		else if (a[mid]>b)
//			j=mid-1;
//		else 
//			return mid+1;
//	}
//	
//	return 0;	
//}
// int main()
//{
//	int q;
//	int a[]={1,2,3,4,5,6,7,8,9};
//	int sz=sizeof(a)/sizeof(a[0]);
//	printf("������Ҫ���ҵ�����");
//	scanf("%d",&q);
//	int ret=find(a,q,sz);
//	if (ret==0)
//		printf("δ�ҵ�����");
//	else 
//		printf("�����ڵ�%dλ",ret);
//	return 0;
//} 

 //�����ж� 
//int is_prime(int
//{
//	 int x=2;
//	 for(x=2;x<=sqrt(a);x++)
//	 {
//	 	if (a%x==0)
//	 		return 0;
//	 }
//	 return 1;
//} 
//int main()
//{
//	int i =0;
//	for (i=100;i<=200;i++)
//	{
//		if(is_prime(i)==1)
//			printf("%d\n",i);
//	}
//	return 0;
//}



//����������swap��x,y�����Լ������ڴ�  �˳������󲻻�ı�ԭ����������Ҫ��ָ�� ֱ�Ӹı���ڴ��µ�ȡֵ
//void swap(int* x,int* y)
//{
//	int c=0;
//	c=*x;
//	*x=*y;
//	*y=c;
//	
//}
//int main()
//{
//	int a=1;
//	int b=2;
//	swap(&a,&b);
//	printf("%d""%d",a,b);
//	return 0;
//}



//�ȴ�С 
//int main()
//{
//	int i=0;
//	int j=1;
//	int c=i>j?i:j;
//	printf("%d",c);
//	char a[]="hello world";
//	memset(a,'*',5);
//	printf("%s",a);
//	return 0;
//} 

//����������ַ��ĵ�ַ 
//int main()
//{
//	int a[]={10};
//	printf("%p",a);
//	return 0;
//}
