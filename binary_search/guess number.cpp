#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void menu()
{
	//下一次游戏先清屏 恢复初始状态 ,搞错了，应该再上一次游戏结束时清屏，而不是下一次开始时清屏
	printf("******1.play******\n");
	printf("******0.exit******\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int pattern=0;
	//外层do while用于游戏开始或者退出
	//内层do while用于判断猜的与实际的大小关系 
	do
	{
		menu();
		printf("选择:>");
		scanf("%d",&pattern);
		switch(pattern)
		{
			case 0:
				printf("退出游戏");break;
			case 1:
				printf("game start!!\n");break;
			default:
				printf("请重新选择!!\n");break;
		}
		if(pattern==1)
		{
			int ret=rand()%100+1;
			printf("your goal is to guess a number between 1 and 100\n");
			//猜对了，下一轮游戏；猜错了，继续猜直到猜对 
			int flag=0;//猜错flag为1，变成once again鼓励一下 
			do
			{
				if(flag==0) 
				{
					printf("please input what you guess:>");
				}
				int guess=0;
				scanf("%d",&guess);
				if(ret==guess)
				{
					printf("猜对啦！\n"); 
					printf("即将回到菜单...") ;
					Sleep(2000);
					system("cls");//清屏重新选择 
					break;
				}
				else if(guess>ret)
				{
					printf("too big!");
					printf("once again!\nplease input what you guess:>");
					flag=1;
				}
				else
				{
					printf("too small!");
					printf("once again!\nplease input what you guess:>");
					flag=1;
				}
			}while(flag);//flag变成1，再次进入循环直接跳过flag==0失效 
		}
	}while(pattern);
	return 0;
}
