//打印 1/1-1/2+1/3-1/4......+1/99_1/100
#include<stdio.h> 
double print(int n)
{
	int flag=1;
	int i=1;
	double res=0;
	while(i<=n)
	{
		res+=flag*(1.0/i);
		i++;
		flag=-flag;
	}
	return res;
}
int main()
{
	while(1) 
	{
		int n=0;
		scanf("%d",&n);
		if(n==-1) break;
		double ret=print(n);
		printf("%lf\n",ret);
	}
	return 0;
}
