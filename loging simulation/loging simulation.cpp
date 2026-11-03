//模拟登录，错误需要提示，三次强制退出
#include<stdio.h> 
#include<windows.h>
#include<string.h>
int main()
{
	printf("welcome!!!\n");
	Sleep(1000);

	int i=1;
	while(i<=3)
	{
		printf("please inpuut your account name and password:>");
		char an[50]="0";
		char pw[30]="0";
		scanf("%s %s",an,pw);
		//比较两字符串是否相同不能用"=" 。可以用strcmp(char1,char2) ,
		//strcmp函数 返回0，则俩字符串相同，否则不同,头文件为 <string.h> 
		if((strcmp(an,"system")==0) && (strcmp(pw,"123")==0))
		{
			system("cls");
			printf("welcome back!!!");
			Sleep(2000);
			break;
		}
		else
		{
			if(i==3)//第三次如果输入正确就会直接break，没有break就是密码错了进入else提示机会用完了 ; 
			{
				printf("you've used up your chances!!!");
				printf("force to quit!!!");
			}
			else
			{
				system("cls") ;
				printf("incorrect account or password\nyou still have %d chance\n",3-i);
			}
		}
		i++;
	}
	return 0;
}
