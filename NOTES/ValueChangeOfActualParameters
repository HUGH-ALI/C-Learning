//数值交换
swap(int x,int y) 
{
	int c=0;
	c=x;
	x=y;
	y=c;
}
int main()
{
	int a=10,b=20;
	printf("before swap:%d %d\n",a,b);
	swap(a,b);
	printf("after swap:%d %d",a,b);
	return 0;
 } 
// 结果：a,b的值并没有互换
//原因：swap(a,b) 只是将a,b的值传给了参数, 参数的值只是a,b实参的临时 拷贝。本质原因是
//假设a,b的 存储地址一个是 00a 一个是 00b ,而 参数使用时的产生存储数值的 临时地址是 00c,00d,函数交换的只是
// 在00c,00d中存储的值，而不是交换在 00a 00b 存储的值，所以利用函数改变实参的方式是传递实参地址，间接改变实参的值 
// 修改： 
 swap(int* x,int* y) 
{
	int c;
	c=*x;
	*x=*y;
	*y=c;
}
int main()
{
	int a=10,b=20;
	printf("before swap:%d %d\n",a,b);
	swap(&a,&b);
	printf("after swap:%d %d",a,b);
	return 0;
 } 
