//求数组最大公约数
//最大公约数：能同时整除所有数的最大值

#include<stdio.h>
void min(int*arr , int* len)
{
	if(arr>=len)
	{
		return;
	}
	int x;
	if((*arr)<*(arr+1))
	{
		x=*arr;
		*arr=*(arr+1);
		*(arr+1)=x;
	}
	return min(arr+1,len);
}
	
int main()
{
	int arr[100] ={};
	int i=0;
	while(scanf("%d",&arr[i])==1&&arr[i]!=-1)
	{
		i++;
	}
	if(i == 0)
    {
        printf("没有输入数字\n");
        return 0;
    }
    min(arr,arr+i-1);
    int ret=arr[i-1] ;
    printf("最小数是:%d\n",ret) ;
    
    while(ret>=1)
    {
    	int flag=1;
    	for(int j=0;j<i;j++)
    	{
    		if(arr[j]%ret!=0)
    		{
    			flag=0;
    			break;
			}
		}
		if(flag==1)
		{
			break;
		}
		ret--;
	}
	
    printf("数组所有数的最大公约数是：%d\n", ret);
	return 0;
}
