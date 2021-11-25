#include<stdio.h>
int n;
int bcn(int n,int k,int dp[][n])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(j==0||j==i)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
		}
	}
	return dp[n][k];
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
			dp[i][j]=0;
		}
	}
	for(k=0;k<=n;k++)
	{
		result=bcn(n,k,dp);
		printf("c(%d,%d)-->%d\n",n,k,result);
	}
}
