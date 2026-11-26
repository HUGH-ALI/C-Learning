#include "game.h"
void menu()
{
	printf("****************\n");
	printf("****1.play******\n");
	printf("****0.exit******\n");
	printf("****************\n");
	printf("玩家请选择:>");
}

void iniboard(char mine[ROWS][COLS],int row,int col)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			mine[i][j]='0';
		}
	}
}


void blind_board(char arr[ROWS][COLS],int row,int col)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			arr[i][j]='*';
		}
	}
}


void board_show(char arr[ROWS][COLS],int row,int col)
{
	int i=0;
	for(i=0;i<=row;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		printf("%d ",i);
		for(int j=1;j<=col;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}



void inidanger(char mine[ROWS][COLS],int row,int col)
{
//	int i=0;
//	for(i=1;i<row*col;i++)
//	{
//		int x=rand()%row+1;
//		int y=rand()%col+1;
//		if(mine[x][y]=='1')
//		continue;//continue不会跳过i++导致雷不足80 
//		else
//		mine[x][y]='1';
//	}
	int cont=0;
	while(cont<10)//总共80个雷cont=79, 满足 < 80 → 放雷，cont 变成 80
	{
		int x=rand()%row+1;
		int y=rand()%col+1;
		if(mine[x][y]!='1')
		{
			mine[x][y]='1';
			cont++;
		}
		else continue;
	}
}

//11*11 判断周围雷数 
char count(char mine[ROWS][COLS],int x,int y)
{
	int cont=0;
	int i=x-1,j=y-1;
	for(i=x-1;i<=x+1;i++)
	{
		for(j=y-1;j<=y+1;j++)
		{
			if(mine[i][j]=='1')
			cont++;
		}
	}
	char c=cont+'0';
	return c;
}

int win(char arr[ROWS][COLS],int row,int col)
{
	int cont=0;
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			if(arr[i][j]=='*')
			cont++;
		}
	}
	return cont;
}

void open(char mine[ROWS][COLS], char arr[ROWS][COLS], int x, int y)
{
	if(arr[x][y]!='*')
	return;
	arr[x][y]=count(mine,x,y);
	if(arr[x][y]=='0')
	{
		open(mine,arr,x-1,y-1);
        open(mine,arr, x-1,y);
        open(mine,arr,x-1,y+1);
        open(mine,arr,x,y-1);
        open(mine,arr,x,y+1);
        open(mine,arr,x+1,y-1);
        open(mine,arr,x+1,y);
        open(mine,arr,x+1,y+1);
	}
}
