//函数实现二分法优化查找速度
//严格增长数组，输入-1结束输入 
int binary_serch(int x,int arr[],int sz) 
{
	int left = 0;
    int right = sz;
    int m;
    int flag=0;
		while(left<=right)
	{
		if(arr[m]<x)
		{
			left=m+1;
			m=(left+right)/2;
		}
		else if(arr[m]>x)
		{
			right=m-1;
			m=(left+right)/2;
		}
		else
		{
			flag=1;
			return m;
		}
	}
	if(flag==0)
	{
		return -1;
	}
}
	
int main()
{
	printf("请输入数组最大长度:>");
	int n=0;
	scanf("%d",&n);
	int arr[n];
	int i=0;
	printf("\n请输入数组:>");

//	1. 先执行 `scanf("%d", &arr[i])`
//	   成功读到整数：返回 `1`，把读到的值放进 arr[i]，继续往后判断 arr[i] != -1
//	   读失败（输入字母 / Ctrl+Z）：返回不是 1，直接跳出循环，后面的 arr[i]!=-1 不执行
//	2. 如果 scanf 成功返回 1，再判断 arr[i] != -1
//	   如果读到的数字是 -1 → 条件为假，退出循环

	while(scanf("%d", &arr[i]) == 1 && arr[i] != -1)
	{
		i++;
		if(i>n)
		{
			printf("达到最大长度，停止录入\n");
			break;
		}
	}
	int x;
	printf("请输入要找的数:>");
	scanf("%d",&x);
	int ret=binary_serch(x,arr,i);
	if(ret>0)
	printf("%d",ret);
	else
	printf("找不到");
	return 0;
 } 
