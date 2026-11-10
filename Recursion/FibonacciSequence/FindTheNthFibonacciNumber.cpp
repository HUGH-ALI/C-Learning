//返回第n个斐波那契数的值 
//斐波那契数列：从第三个数开始每个数是前两个数的和
// 1 1 2 3 5 8 13 21 34..... 
#include<stdio.h>
#include<time.h>

//递归
// int count=0;
// int fib(int n) 
// {
// 	if(n==3) count++;
// 	if(n<=2)//第一次错误原因:在if前面加了else 
// 	return 1;
// 	else 
// 	return fib(n-1)+fib(n-2) ;
// }
//n=5:  fib(4)+fib(3)=fib(3)+fib(2)+fib(2)+fib(1) =fib(2)+fib(1)+1+1+1=1+1+3=5
//40
//第40个斐波那契数是:1411915464
//耗时：-0.260000 秒
//n=3计算了 39408587 次
//50
//第50个斐波那契数是:-365030719
//耗时：-30.358000 秒
//n=3计算了 551968267 次
//n超过50就很慢了，而且递归过程n越小重复计算次数越多没用上之前算的结果.求第n个斐波那契数不适合用递归实现 

int fib(int n)
{
	int a=1,b=1,c=0;
	if(n==3) count++;
	if(n<=2)
	return 1;
	else
	{
		while(n>2)
		{
			c=a+b;
			a=b;
			b=c;
			n--;
		}
	}
	return c;
} 
 //n=5: fib(5>2):c=1+1=2,a=1,b=2,n=4;n=4>2,c=1+2=3,a=2,b=3,n=3;n=3>2,c=5,a=3,b=5,n=2;n=2!>2结束--> c=5

int main()
{
	int n=0;
	while(scanf("%d",&n)==1 && n!=-1) 
	{
		clock_t start=clock();
		int ret=fib(n);
		printf("第%d个斐波那契数是:%d\n",n,ret);
		clock_t end=clock();
		double time_cost=(double)(start-end)/CLOCKS_PER_SEC;
		printf("耗时：%.6f 秒\n",time_cost);
		printf("n=3计算了 %d 次\n",count);
	}
	return 0;
}
