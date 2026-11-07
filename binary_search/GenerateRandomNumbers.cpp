#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//int main()
//{
//	int ret=rand();
//	printf("%d\n",ret);
//	return 0;
//}
//没有设置随机数种子默认的种子是1.等价于：程序一上来自动执行了 `srand(1)`,每次重新运行随机数相同 ,此处为41 

//int main()
//{
//	//srand(2) ;
//	srand(3) ;
//	int ret1=rand();
//	int ret2=rand();
//	//不管你写多少个 `srand`，只有最后一次执行的 srand 生效，即ret1 和 ret2 全部用的是 srand (3)，前面的 srand (2) 直接作废了 
//	printf("%d %d\n",ret1,ret2);
//	return 0;
//}
//设置了固定的随机数种子， 每次重新运行随机数相同，此处为48 7196 

//怎么设置变化的随机数种子呢-->时间一直在变化，将当前时间作为随机数种子就行了 
//srand: 参数要求是无符号整型 unsigned int，头文件是 <stdlib.h>
//获取当前时间： time(NULL)：头文件 <time.h>，获取 当前系统时间（秒数），时间每一秒都不一样，所以种子每次运行都不同
//rand: 头文件是<stdlib.h>,返回一个 0 ~ RAND_MAX 的整数（RAND_MAX 一般是 32767）
//由于 time(NULL)返回的不是无符号整型，所以要强制转换为无符号整型 (unsigned int)time(NULL)

int main()
{
	while(1) 
	{
		srand((unsigned int)time(NULL));
		int ret=rand()%100+1;
		//想要获取 范围在 x~y 以内的随机数 ：rand()%y+x 
		printf("%d\n",ret);
		Sleep(1000);
		//打印随机数发现，连续时间打印出来的随机数是自增的，此代码为例，随机数间隔为3或者4 
	}

	return 0;
}
