#include<stdio.h>
int n;
int mcm(int a[],int i,int j,int dp[][n+1])
{
	int min,k,temp;
	if(i>=j)
	{
		return 0;
	}
	else if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	else
	{
		min=9999;
		for(k=i;k<j;k++)
		{
			temp=mcm(a,i,k,dp)+mcm(a,k+1,j,dp)+(a[i-1]*a[k]*a[j]);
			if(temp<min)
				min=temp;
		}
		dp[i][j]=min;
		return min;
	}
}
void main()
{
	int i,j,result;
	printf("enter the no of matrices");
	scanf("%d",&n);
	int a[n+1],dp[n+1][n+1];
	for(i=0;i<n+1;i++)
	{
		printf("a[%d]",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			dp[i][j]=-1;
		}
	}
	i=1;
	j=n;
	result=mcm(a,i,j,dp);
	printf("minimum number of multiplications are %d",result);
}
