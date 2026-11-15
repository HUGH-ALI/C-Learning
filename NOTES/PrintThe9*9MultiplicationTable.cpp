//1*1=1
//1*2=2 2*2=4
//1*3=3 2*3=6 3*3=9
//1*4=4 2*4=8 3*4=12 4*4=16

#include<stdio.h>
int  main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=-2%d ",j,i,j*i);//%2d是两位数时，不足用空格补齐（右对齐），%-2d是左对齐 
		}
		printf("\n");
	}
	return 0;
}
