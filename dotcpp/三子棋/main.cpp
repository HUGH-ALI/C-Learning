#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int op=0;
	do
	{
		menu();
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
			  printf("gamestart!\n");
			  char arr[ROW][COL]={0};
			  initboard(arr,ROW,COL);
			  board(arr,ROW,COL);
			  char is_win='c';
			  while(is_win=='c')
			  {
			  	playermove(arr,ROW,COL);
			  	is_win=IS_WIN(arr,ROW,COL);
			  	if(is_win!='c')
			  	break;
			  	
			  	computermove(arr,ROW,COL);
			  	is_win=IS_WIN(arr,ROW,COL);
			  }
			  if(is_win=='x')
			  printf("玩家胜出！\n");
			  if(is_win=='o')
			  printf("人机胜出！\n");
			  if(is_win=='d') 
			  printf("平局\n");
			  break;
			}
			case 0:
			{
			  break;
			}
			default:
			{
		      printf("选择错误！\n");
			  continue;
			}
		}
	}while(op);
	return 0;
}
