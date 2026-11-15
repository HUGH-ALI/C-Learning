#include<stdio.h>
// char level(float n)
// {
// 	int s=n/10;
// 	switch(s)
// 	{
// 		case 9: return 'A';
// 		case 8:return 'B';
// 		case 7:return 'C';
// 		case 6:return 'D';
// 		default:return 'E';
// 	}
// }
char level(float n)
{
	if(n>=90) return 'A';
	else if(n>=80 && n<=89) return 'B';
	else if(n>=70 && n<=79) return 'C';
	else if(n>=60 && n<=69) return 'D';
	else return 'E';
}
int main()
{
	float n;
	scanf("%f",&n);
	printf("%c",level(n));
	return 0;
}
