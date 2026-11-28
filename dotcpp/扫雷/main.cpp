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
					printf("--------扫雷--------\n");
					printf("\n");
					
					int flag=1;
					while(flag)
					{
						int x;
						int y;
						printf("玩家输入坐标(负数为标记，例 -2 -3；正数翻开):");
						scanf("%d %d",&x,&y);
						
						//标记逻辑：输入负数
						if(x < 0 && y < 0)
						{
							int rx = -x;
							int ry = -y;
							if(rx<=0 || ry<=0 || rx>ROW || ry>COL) 
							{
								printf("超出范围，请重新输入!\n");
								continue;
							}
							//已经翻开数字，不能标记
							if(arr[rx][ry] >= '0' && arr[rx][ry] <= '8')
							{
								printf("已经翻开的格子不能标记！\n");
								continue;
							}
							if(arr[rx][ry] == '*')
							{
								arr[rx][ry] = 'F';//插旗子
							}
							else if(arr[rx][ry] == 'F')
							{
								arr[rx][ry] = '*';//取消旗子
							}
							board_show(arr,ROW,COL);
							//判断胜利
							if(win(arr,mine,ROW,COL)==1)
							{
								printf("恭喜你已经排除所有雷！\n");
								flag=0;
							}
							continue;
						}

						//翻开逻辑（正数）
						if(x<=0 || y<=0 || x>ROW || y>COL) 
						{
							printf("超出范围，请重新排除!\n");
							continue;
						}
						//旗子不能翻开
						if(arr[x][y] == 'F')
						{
							printf("该位置已经插旗，不能翻开！\n");
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
							open(mine,arr,x,y);
							printf("\n");
							board_show(arr,ROW,COL);
							
							if(win(arr,mine,ROW,COL)==1)
							{
								printf("恭喜你已经排除所有雷！\n");
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

