#include<stdio.h> 
char print(char* str)
{
	if(*str!='\0')
	{
		printf("%c ",*str);
		return print(str+1);
	}
	else return '#';
}


int main()
{
	char arr[100]="";
	int i=0;
	//错 
//	while(scanf("%c", &arr[i]) == 1 && arr[i] != -1)
//	{
//		i++;
//		scanf("%c",arr[i]);
//	}
	//arr 数组名，代表首元素的地址 → 本身就是地址，scanf("%s", arr) 不用 `&`
	//arr[i] 是数组里单独这一个元素，它就是普通变量，不是地址 → 读它就要 &arr[i]
	//%c 读取的是字符，字符在内存里是 ASCII 码。
	//-1 不是一个字符！不能用输入 -1 当结束标记（%c是一个一个读单个字符，输入`-1`会被拆成'-' 、'1'两个字符）
	//如果想标记结束，一般用特殊字符，比如 '#'（# 作为结束符）
	//while 条件里已经读了一个字符，循环体里又 scanf，重复读取了
	//scanf("%c", &arr[i]) == 1尝试读取一个字符，成功读到字符就返回 1并存入arr[i]，读取失败返回不是 1，循环直接退出。 
	//`&&`短路：读到字符之后，才判断 arr[i] != '#' ;是读取成功了再判断成功读取的这个字符是不是\0 
	//printf("%s",arr);
	//printf("%s") 要求字符串末尾必须有 '\0',所以要手动添加 
	
	
	while( scanf("%c",&arr[i])==1 && arr[i]!='#')
	{
		i++;
	}
	arr[i]='\0';
	//printf("%s\n",arr);
	print(arr);
	return 0;
}
