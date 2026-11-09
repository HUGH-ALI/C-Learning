//因为数组是int型的我只能用输入某一个整数来停止输入，那么我就只能在数组结束时输入这个数，如果在结束输入前还有一个这个数的输入那么这个位置往后的数都会被扔掉
//12 3 43 5 12 -1 67 8 234 -1； 67 8 234 -1都会被扔掉不会存入数组
#include<stdio.h>
void find_max(int* arr,int* len)
{
	if(arr>=len)
	{
		return;
	}
	int x=0;
	int max=*arr;
	if((*arr) > (*(arr+1)))
	{
		x=*arr;
		*arr=*(arr+1);
		*(arr+1)=x;
	}
	return find_max(arr+1,len);
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
	find_max(arr,arr+i-1);//arr即arr[0] 
	ret=arr[i-1];
	printf("the max value of this arry is %d\n",ret);
	return 0;
}
