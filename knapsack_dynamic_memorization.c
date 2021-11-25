#include<stdio.h>
int k[100][100];
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
		return y;
}
int knapsack(int n,int wt[],int val[],int W)
{
	if(n==0||W==0)
	{
		return 0;
	}
	else if(k[n][W]!=-1)
	{
		return k[n][W];
	}
	else
	{
		if(wt[n-1]<=W)
		{
			k[n][W]=max(val[n-1]+knapsack(n-1,wt,val,W-wt[n-1]),knapsack(n-1,wt,val,W));
		}
		else
		{
			k[n][W]=knapsack(n-1,wt,val,W);
		}
	}
	return k[n][W];
}
void main()
{
	int n,i,j,W,result;
	printf("enter the no of items");
	scanf("%d",&n);
	int val[n],wt[n];
	printf("enter the bag weight");
	scanf("%d",&W);
	for(i=0;i<n;i++)
	{ 
		printf("Enter the %d item wt and its value",i+1);
		scanf("%d %d",&wt[i],&val[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			k[i][j]=-1;
		}
	}
	result=knapsack(n,wt,val,W);
	printf("The maximum profit is %d",result);
}
