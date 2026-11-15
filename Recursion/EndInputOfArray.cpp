# 简单加密
//#include<stdio.h> 
//int main()
//{
//	char ch[100]="";
//	int i=0;
//	//&& ch[i]!='#'
//	while(scanf("%c",&ch[i])==1 && ch[i]!='#')
//	{
//		i++;
//	}
//	printf("\n");
//	int j=0;
//	while(j<i)
//	{
//		printf("%c",ch[j]+4);
//		j++;
//	}
//	return 0;
//}


//终于解决了输入必须以一个字符结束的问题 scanf("%s", ch);
//%s可以输入字符串而且可以直接回车结束输入 ，之前搞忘记有%s这个东西了,但是要求输入的元素为个位数或者单个字母 
//不然判断ch[i]只会一个字节一个字节拿 

#include<stdio.h> 
int main()
{
	char ch[100]="";
	scanf("%s",ch);
	int i=0;
	while(ch[i]!='\0')
	{
		printf("%c",ch[i]+4);
		i++;
	}
	return 0;
}


//#include<stdio.h> 
//int main()
//{
//	char ch[100]="";
//	scanf("%s",ch);假设输入是12345 
//	int i=0;
//	while(ch[i]!='\0')
//	{
//		if(ch[i]%2==0)
		//注意ch[i] 不是拿1%2，2%2，3%2，4%2,ch存的是字符的ASCLL码，而偶数的ASCLL码是偶数，奇数的ASCLL码是奇数
		// 12345 对应的ASCLL码为：49 50 51 52 53
//		{
//			printf("%c ",ch[i]);
//			i++;
//		}
//		else 
//		{
//			i++;
//			break;
//		}
//	}
//	return 0;
//}
