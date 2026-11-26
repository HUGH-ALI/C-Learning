#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int op;
	do{
		menu();
		char arr[ROWS][COLS];//信息盘
		char mine[ROWS][COLS]; //雷盘 
		iniboard(mine,ROW,COL);//arr全0 
		blind_board(arr,ROW,COL);//初始信息盘全** 
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				{
					inidanger(mine,ROW,COL);//布置雷 
					printf("--------扫雷--------\n");
					board_show(arr,ROW,COL);
					//printf("\n");
					//board_show(mine,ROW,COL);测试 
					printf("--------扫雷--------\n");
					printf("\n");
					
					int flag=1;
					while(flag)
					{
						int x;
						int y;

						printf("玩家输入要排雷的坐标：");
						scanf("%d %d",&x,&y);
						
						if(x<=0 || y<=0 || x>ROW || y>COL) 
						{
							printf("超出范围，请重新排除!\n");
							continue;
						}
						
						if(mine[x][y]=='1')
						{
							printf("游戏失败！\n");
							board_show(mine,ROW,COL);
							flag=0;
						}
						else
						{
//							arr[x][y]=count(mine,x,y);
//							int ret=count(mine,x,y)-'0';
//							if(ret==0)
//							{
//								for(int i=x-1;i<=x+1;i++)
//								{
//									for(int j=y-1;j<=y+1;j++)
//									{
//										if(arr[i][j]!='*')
//										continue;
//										else
//										arr[i][j]='0';
//									}
//								}
//							}
//不继续递归检查其他八个坐标那么输入上个坐标周围八个坐标是已经检查出来的信息会被覆盖 
							open(mine,arr,x,y);
							//board_show(mine,ROW,COL);测试 
							printf("\n");
							board_show(arr,ROW,COL);
							
							if(win(arr,ROW,COL)==10)
							{
								printf("恭喜你已经排除所有雷！");
								flag=0;
								break;
							}
						}
					}
				break;
				}
		
			case 0:
				printf("下次再见！\n");
				break;
			default:
				printf("选择错误！\n");
				break;
		}
	}while(op);
	return 0;
}


