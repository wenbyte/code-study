
#include "game1.h"


void game()
{	
	char ret;
	char arr[ROW][COL]={0};
	Initarr(arr,ROW,COL);//��ʼ������Ϊ�ո� 
	Displayarr(arr,ROW,COL);//չʾ����
	while(1)
	{
		playermove(arr,ROW,COL);//������� 
		Displayarr(arr,ROW,COL);
		ret=Iswin(arr,ROW,COL);
		if (ret!='c')
			break;
		computermove(arr,ROW,COL);//�������� 
		Displayarr(arr,ROW,COL);
		if (ret!='c')
			break;
	}
	if (ret=='*')
		printf("��Ϸ��������һ�ʤ��:)");
	else if (ret=='#')
		printf("��Ϸ���������Ի�ʤ:("); 
	else if (ret=='d')
		printf("��Ϸ������ƽ��-----") ;
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
	printf("�����룺");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default :
			printf("�����������������\n");
			goto error;
			break;
			
	
	
	}
}

int main() 
{
	test();
	return 0;
}
