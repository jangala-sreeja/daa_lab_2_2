#include<stdio.h>
int fib(int n)
{
	int f[n],i;
	if(n<0)
	{
		return -1;
	}
	f[0]=0;
	f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=f[i-2]+f[i-1];
	}
	return f[n];
}
void main()
{
	int n,result;
	printf("enter the fib number");
	scanf("%d",&n);
	result=fib(n);
	printf("fib(%d)->%d",n,result);
}
