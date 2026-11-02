#include<stdio.h>
#include<windows.h>
int main()
{
	char arr1[]="#######################";
	char arr2[]="welcom to my channel!!!";
	int len=sizeof(arr1)/sizeof(arr1[0]);
	//erro原因: 
	//int left=0,right=len-1;第一次打印左边第一个替换了但是右边第一个没有 
	//printf("%d\n",len);len为24，连 \0 也 算进去了，第一次arr2的\0 与arr1的\0替换看不见效果 
	//所以应该是 right 因该是 len-2 ;或者改用strlen不会算上\0 :strlen(arr1)
	int left=0,right=len-2;
	while(left<=right)//left=right，元素个数为奇数
	{
		arr1[left]=arr2[left];
		arr1[right]=arr2[right];
		
		if(left<=right)
		{
			system("cls");//让CMD执行 sysytem里的语句 cls是清屏 
		}
		
		printf("%s\n",arr1);
		Sleep(1000);//每执行一次printf 延迟1秒执行下一次printf 
		//sleep与system的头文件是<windows.h> 
		left++;
		right--;
	}
	return 0;
}
