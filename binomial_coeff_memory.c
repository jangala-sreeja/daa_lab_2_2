#include<stdio.h>
int n;
int bcn(int n,int k,int dp[][n])
{
	if(k==0||n==k)
	{
		return 1;
	}
	else if(dp[n][k]!=-1)
	{
		return dp[n][k];
	}
	else
	{
		dp[n][k]=bcn(n-1,k-1,dp)+bcn(n-1,k,dp);
		return dp[n][k];
	}
}
void main()
{
	int k,result,i,j;
	printf("enter the n value");
	scanf("%d",&n);
	int dp[n+1][n+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(k=0;k<=n;k++)
	{
		result=bcn(n,k,dp);
		printf("c(%d,%d)-->%d\n",n,k,result);
	}
}
