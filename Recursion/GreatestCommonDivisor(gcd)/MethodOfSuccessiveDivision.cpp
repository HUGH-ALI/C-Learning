//辗转相除法
//a=12,b=18,c=a%b=12;
// a=b=18,b=c=12,c=a%b=6;
// a=b=12,b=c=6,c=a%b=0; 当c=0,b的值就是最大公约数的数 
//得出最大公约数就可以快速得出最小公倍数：a*b/最大公约数（a,b原始值） 
#include<stdio.h> 
int main()
{
	int a=0,b=0;
	while(a!=-1 && b!=-1) 
	{
		scanf("%d %d",&a,&b);
		int ret1=a,ret2=b;
		while(a%b)
		{
			int c=a%b;
			a=b;
			b=c;
		}
		int d= ret1*ret2/b;
		printf("最大公约数是:%d\n",b);
		printf("最小公倍数是:%d",d);
	}
	return 0;
}
