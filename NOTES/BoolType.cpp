//bool类型
//boll值有两个 true/false 
bool judge(int x)
{
	if(x%2==0)
	return true;
	else
	return false;
}
int main()
{
	int a=0;
	scanf("%d",&a);
	if(judge(a))
	{
		printf("%d是偶数",a);
	}
	return 0;
}
