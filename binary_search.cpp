#include<stdio.h>

int main() 
{
		int arr[]={1,2,3,4,5,6,7,8,9,10} ;
	int a;
	while(1)
	{
		printf("\n要找的数:>");
		scanf("%d",&a);
		int left = 0;
        int right = sizeof(arr)/sizeof(arr[0]) - 1;
        int m = (left + right)/2;//每次查找left,right,m都要恢复初始值 
        int flag=0;
		if(a==0)break;
			while(left<=right)
		{
			if(arr[m]<a)
			{
				left=m+1;
				m=(left+right)/2;
			}
			else if(arr[m]>a)
			{
				right=m-1;
				m=(left+right)/2;
			}
			else
			{
				printf("%d 的下标为 %d",a,m);
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("找不到");
		}
	}
	
	return 0;
}
