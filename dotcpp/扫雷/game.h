#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
void menu(void);
void iniboard(char mine[ROWS][COLS],int row,int col);
void board_show(char arr[ROWS][COLS],int row,int col);
void blind_board(char arr[ROWS][COLS],int row,int col);
void inidanger(char mine[ROWS][COLS],int row,int col);
char count(char mine[ROWS][COLS],int x,int y);
int win(char arr[ROWS][COLS],int row,int col);
void open(char mine[ROWS][COLS], char arr[ROWS][COLS], int x, int y);

