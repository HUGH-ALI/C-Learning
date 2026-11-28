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
	int cont=0;
	while(cont<10)
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

//全部非雷格子已经翻开返回1，代表胜利
int win(char arr[ROWS][COLS],char mine[ROWS][COLS],int row,int col)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			//不是雷，但是还是*，没有翻开，没胜利
			if(mine[i][j] == '0' && arr[i][j] == '*')
			{
				return 0;
			}
		}
	}
	return 1;
}

void open(char mine[ROWS][COLS], char arr[ROWS][COLS], int x, int y)
{
	//不是*（数字或者F旗子）直接返回，不翻开
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

