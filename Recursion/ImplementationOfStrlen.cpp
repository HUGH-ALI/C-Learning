#include<stdio.h>
int len(char* arr)
{
	if(*arr!='#')
	return 1+len(arr+1);
	else
	return 0;
}
int main()
{
	char arr[100]="";
	int i=0;
	while(scanf("%c",&arr[i])==1 && arr[i]!='#')
	{
		i++;
	}
	//#只是用来结束输入的我并不想让他计入数组 
	//虽然最终结果是结束输入的#前面的长度，但由于是先写入再判断的，实际上#还是被写入了数组
	//数组实际的长度也是结果+1，多的1就是# 
	int ret=len(arr);
	printf("arr的长度是:>%d",ret);
	return 0;
}
