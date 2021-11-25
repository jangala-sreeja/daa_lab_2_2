#include<stdio.h>
int max(int x,int y)
{
	return x>y?x:y;
}
int knapsack(int n,int wt[],int val[],int W)
{
	if(n==0 || W==0)
	{
		return 0;
	}
	else
	{
		if(wt[n-1]<=W)
			return	max((val[n-1]+knapsack(n-1,wt,val,W-wt[n-1])),knapsack(n-1,wt,val,W));
		else
			return knapsack(n-1,wt,val,W);
	}
}
void main()
{
	int n,i,j,W,result;
	printf("enter the no of items");
	scanf("%d",&n);
	int val[n],wt[n];
	for(i=0;i<n;i++)
	{ 
		printf("Enter the %d item wt and its value",i+1);
		scanf("%d %d",&wt[i],&val[i]);
	}
	printf("enter the bag weight");
	scanf("%d",&W);
	result=knapsack(n,wt,val,W);
	printf("The maximum profit is %d",result);
}
