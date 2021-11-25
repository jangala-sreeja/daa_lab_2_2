#include<stdio.h>
int k[100][100];
int max(int x,int y)
{
	return x>y?x:y;
}
int knapsack(int n,int wt[],int val[],int W)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		k[i][0]=0;
	}
	for(j=0;j<=W;j++)
	{
		k[0][j]=0;	
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(wt[i-1]<=j)
			{
				k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
			}
			else
			{
				k[i][j]=k[i-1][j];
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=W;j++)
			{
				printf("%d\t",k[i][j]);
			}
	}
	return k[n][W];
}
void main()
{
	int n,i,j,W,result;
	int k[100][100];
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
	result=knapsack(n,wt,val,W);
	printf("The maximum profit is %d",result);
}
