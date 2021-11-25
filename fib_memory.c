#include<stdio.h>
fib(int n,int a[])
{
	if(n==0||n==1)
	{
		a[n]=n;
	}
	else
	{
		if(a[n]==-1)
			a[n]=fib(n-1,a)+fib(n-2,a);
	}
	return a[n];
}
void main()
{
	int n,result,i;
	printf("enter the fib number");
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<=n;i++)
	{
		a[i]=-1;
	}
	result=fib(n,a);
	printf("fib(%d)->%d",n,result);
}
