#include<stdio.h>
#include<math.h>
int bin[100],n,rb[100],final[100],visit[100];
void binary(int n)
{
	int q=0,rem;
	while(n!=0)
	{
		rem=n%2;
		bin[q]=rem;
		q++;
		n=n/2;
	}
}
void reverse()
{
	int q=0,i;
	for(i=n-1;i>=0;i--)
	{
		rb[q]=bin[i];
		q++;
	}
}
void main()
{
	int i,j,W,k,profit,temp,max=0;
	printf("enter number of items");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("enter the bag weight");
	scanf("%d",&W);
	for(i=0;i<n;i++)
	{
		printf("enter %d weight and values",i+1);
		scanf("%d %d",&wt[i],&val[i]);
	}
	for(i=0;i<pow(2,n);i++)
	{
		profit=0;
		temp=W;
		binary(i);
		reverse();
		for(j=0;j<n;j++)
		{
			if(bin[j]!=0 && wt[j]<=temp)
			{
				profit=profit+val[j];
				temp=temp-wt[j];
			}
		}
		if(profit>max)
		{
			max=profit;
			for(k=0;k<n;k++)
			{
				final[i]=bin[i];
			}
		}
	}
	printf("The maximum profit is %d",max);
/*	for(k=0;k<n;k++)
		{
				printf("%d",final[i]);
		}*/
}
