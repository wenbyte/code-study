#define ROW 3
#define COL 3
#include<time.h>
#include <stdio.h>
#include <stdlib.h>

//ÉùÃ÷º¯Êý
void Initarr(char arr[ROW][COL],int row,int col) ;
void Displayarr(char arr[ROW][COL],int row,int col) ;
void playermove(char arr[ROW][COL],int row,int col) ;
void computermove(char arr[ROW][COL],int row,int col) ;
char Iswin(char arr[ROW][COL],int row,int col);
int Isfull(char arr[ROW][COL],int row,int col);
