#include<stdio.h> 
void print(int n)
{
	if(n<10)
	{
		printf("%d ",n);
		return;
	}
//	//顺序 
//	print(n/10);
//	printf("%d ",n%10); 
	//逆序 
	printf("%d ",n%10); 
	print(n/10);
}
//123
//①n=123 ---> 123！<10 ---> 调用print（n=123 只到达调用函数这一步还没结束（printf n%10还没执行）） --->n=12
//②n=12 ---> 12!<10 --->  调用print (n=12 只到达调用函数这一步还没结束（printf n%10还没执行）) --->n=1
//③n=1 ---> 1<10 ---> print n ,return; print(n/10)即print(n=1)结束 ，返回到还没有结束的 n=12。n=12 
//只差 printf n%10还没执行,打印n%10即 12%10=2,打印2 ,print(n=12)结束，返回到没有结束的 n=123，n=123
//只差 printf n%10还没执行,打印n%10即 123%10=3,打印3 ,print(n=123)结束
//重点找出口，此处出口就是n<10
//顺序是先递归找到第一位再取余打印 ，逆序则是先取余打印，再递归去掉个位 
int main()
{
	int x=0;
	printf("what do you want print:>");
	scanf("%d",&x);
	print(x);
	return 0;
}
