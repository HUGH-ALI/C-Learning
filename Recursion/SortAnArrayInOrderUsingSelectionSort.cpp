//35minuts
#include<stdio.h>
void order(int* arr,int* len)
{
//	if(arr>=len)
//	{
//		return;
//	}
//	int x=0;
//	if((*arr) <= (*(arr+1)))
//	{
//		x=*arr;
//		*arr=*(arr+1);
//		*(arr+1)=x;
//	}
//	return oder(arr,len-1);
	//我想每一轮从头开始比把最小的放到最后，然后下一轮忽略上一轮放到最后面的数 ，
	//但是忽略了if()只比较了两个相邻的数把两个中较小的往后放就结束了 ，而不是较小的放到数组最后！！！
	//所以不能忽略最后一个 
	//2 2 3 1 5 7 4
	//2<=2,2与2交换位置 下一次还是从2开始，但最后的四没了 
	
	if(arr>=len)
	{
		return;
	}
	int x=0;
	if((*arr) <= (*(arr+1)))
	{
		x=*arr;
		*arr=*(arr+1);
		*(arr+1)=x;
	}
	order(arr+1,len);//到这里最后一位元素就是最小的了 
	return order(arr,len-1) ;//从头开始最后一位不用管 
}

int main()
{
	int arr[100]={};
	int i=0;
	while(scanf("%d",&arr[i])==1 && arr[i]!=-1)
	{
		i++;
	}
	int ret=0;
	printf("%d\n",i);
	order(arr,arr+i-1);//arr即arr[0] 
	int t=0;
	while(t<i)
	{
		printf("%d ",arr[t]);
		t++;
	}
	
	return 0;
}
