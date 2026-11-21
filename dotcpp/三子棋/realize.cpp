#include"game.h"
 
void menu(void)
{
	printf("****************\n");
	printf("-----1.play-----\n");
	printf("-----0.exit-----\n");
	printf("****************\n");
	printf("玩家请选择:>");
}

void initboard(char arr[][COL],int row,int col)
{
	int i,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j]=' ';
		}
	}
}

void board(char arr[][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			if(j<row-1)
			printf(" %c |",arr[i][j]);
			else
			printf(" %c",arr[i][j]);
		}
		printf("\n");
		
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				if(j<3-1)
				printf("---|");
				else
				printf("---");
			}
			printf("\n");
		}
	}
}

void playermove(char arr[][COL],int row,int col)
{
	int flag=1;
	printf("玩家选择坐标:>");
	while(flag)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x=x-1,y=y-1;
		//printf("%d %d\n",x,y) ;
		if(x<0 || y<0 || x>=row || y>=col)
		{
			printf("超出边界,请重新选择:>");
			continue;
		}
		else if(arr[x][y]==' ')
		{
			arr[x][y]='x';
			board(arr,ROW,COL);
			break; 
		}
		else
		{
			printf("该点已占用请重新选择:>");
		}
	}
}

void computermove(char arr[][COL],int row,int col)
{
	int flag=1;
	printf("人机环节:\n");
	while(flag)
	{
		int x=rand()%(row);
		int y=rand()%(col);
		if(arr[x][y]==' ')
		{
			arr[x][y]='o';
			flag=0;
			board(arr,ROW,COL);
			break;
		}
		else
		{
			continue;
		}
	}
}


char IS_WIN(char arr[][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][0]!=' ')
		return arr[i][0];
	}
	for(i=0;i<col;i++)
	{
		if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i] !=' ')
		return arr[0][i];
	}
	
	if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0]!=' ') 
	{
		return arr[0][0];
	}
	if(arr[1][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[2][0]!=' ') 
	{
		return arr[2][0];
	}
	
	for(i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(arr[i][j]==' ')
			return 'c';
		}
	}
	return 'd';
}

