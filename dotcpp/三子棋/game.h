#include<stdio.h>
#define ROW 3
#define COL 3
//宏定义行列，方便打印不同规格的棋盘，改的时候只需要改宏定义就行
//宏定义最好大写，不然容易与参数搞混 

#include<time.h>
#include<stdlib.h>

void menu();
void initboard(char arr[][COL],int row,int col);
void board(char arr[][COL],int row,int col);
void playermove(char arr[][COL],int row,int col);
void computermove(char arr[][COL],int row,int col);
char IS_WIN(char arr[][COL],int row,int col);
//二维数组作为参数传递时不能 char* arr,这是一维数组传递的指针形式，
//二维数组的是 cahr arr[][col] 列不能省略 
