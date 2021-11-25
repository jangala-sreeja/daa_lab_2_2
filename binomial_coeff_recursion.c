#include<stdio.h>
int n;
int bcn(int n,int k)
{
	if(k==0||n==k)
	{
		return 1;
	}
	else
	{
		return bcn(n-1,k-1)+bcn(n-1,k); ;
	}
}
void main()
{
	int k,result,i,j;
	printf("enter the n value");
	scanf("%d",&n);
	for(k=0;k<=n;k++)
	{
		result=bcn(n,k);
		printf("c(%d,%d)-->%d\n",n,k,result);
	}
}
