//给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321,应输出123
#include<stdio.h>
void print1(int n,int i)
{
	int j=0;
	if(n<10) 
	{
		printf("%d ",n);
		j++;
		return;
	}
	print1(n/10,i); 
	if(j==i)
	printf("%d",n%10);
	else
	printf("%d ",n%10);
	j++;
}

void print2(int n)
{
	if(n<10) 
	{
		printf("%d",n);
		return;
	}
	printf("%d",n%10);
	print2(n/10); 
}

int main()
{
	int n=0;
	scanf("%d",&n);
	
	int i=0,ret=n;
	while(ret>0)
	{
		ret=ret/10;
		i++;
	}
	printf("%d\n",i);
	print1(n,i);
	printf("\n");
	print2(n);
	return 0;
}
