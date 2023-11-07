//游戏模块
#include "game1.h"
#include<stdio.h>
int Isfull(char arr[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{	for(j=0;j<col;j++)
		{
			if(arr[i][j]==' ')
				return 0;
		}
	
	}
	return 1;
}



char Iswin(char arr[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]&& arr[i][0]!=' ')
			return arr[i][0];
		
	}
	for(i=0;i<col;i++)
	{
		if(arr[0][i]==arr[1][i]&& arr[1][i]==arr[2][i]&&arr[0][i]!=' ')
			return arr[0][i];
		
	}
	
	
	if((arr[1][1]==arr[0][2]&& arr[1][1]==arr[2][0]||arr[1][1]==arr[0][0]&&arr[1][1]==arr[2][2]) && arr[1][1]!=' ')
		return arr[1][1];
		
	
	
	if (1==Isfull(arr,ROW,COL) )
		return 'd';
	else 
		return 'c';
}


void computermove(char arr[ROW][COL],int row,int col) 
{
	int x,y;
	printf("电脑走：\n");
	while(1)
	{	x=rand()%row;
		y=rand()%col;
		if(1<=x && 3>=x&& 1<=y && 3>=y)
		{
			if (arr[x][y]==' ')
			{	arr[x][y]='#';
				break; 
			}
			
		}
		
	}
}


void playermove(char arr[ROW][COL],int row,int col)
{	int  i,j;
	
	while(1)
	{	printf("请输入要下的棋子坐标:\n");
		scanf("%d%d",&i,&j);
		if(1<=i && 3>=i&& 1<=j && 3>=j)
		{
			if (arr[i-1][j-1]==' ')
			{	arr[i-1][j-1]='*';
				break; 
			}
			else
				printf("该位置已被占用\n"); 
		}
		else
			printf("输入错误\n"); 
	}
}


void Initarr(char arr[ROW][COL],int row,int col) 
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			arr[i][j]=' ';
			
	}
}



void Displayarr(char arr[ROW][COL],int row,int col) 
{
	int i,j;
	for(i=0;i<row;i++)
	{
	 	for(j=0;j<col;j++)
		{if(j<col-1)//不包括最后一列 
			printf(" %c |",arr[i][j]);
		else
			printf(" %c \n",arr[i][j]);
		}
		j=0;
		if(i<row-1)//不包括最后一行 
		{
		while(j<row*4-1)
		{	if((j+1)%4==0&&j!=0)
				printf("|");
			else 
				printf("-");
			j++;
		}
		printf("\n");
		}
	}
}
