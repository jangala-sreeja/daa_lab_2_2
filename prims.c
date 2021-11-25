#include<stdio.h>
void main()
{
	int n,i,j,min=999,c=0,loc,k,sum=0;
	printf("enter number of nodes");
	scanf("%d",&n);
	int m[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("m[%d][%d]",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	int wt[n],p[n],visit[n];
	wt[0]=p[0]=0;
	visit[0]=0;
	for(i=1;i<n;i++)
	{
		p[i]=-1;
		wt[i]=999;
		visit[i]=0;
	}
	i=0;
	while(c<n)
	{
		min=999;
		if(visit[i]==0)
		{
			visit[i]=1;
			loc=i;
			c++;
		}
		for(j=0;j<n;j++)
		{
			if(visit[j]==0&&m[i][j]!=0)
			{
				if(m[i][j]<wt[j])
				{
					wt[j]=m[i][j];
					p[j]=i;
					if(m[i][j]<min)
					{
						min=m[i][j];
						loc=j;
					}
				}
			}
		}
		if(loc==i)
		{
			min=999;
			for(k=0;k<n;k++)
			{
				if(visit[k]==0)
				{
					if(wt[k]<min)
					{
						min=wt[k];
						loc=k;
					}
				}
			}
		}
		i=loc;
	}
	for(i=0;i<n;i++)
	{
		sum=sum+wt[i];
		printf("%d 's parent is %d\n",i,p[i]);
	}
	printf("\n SUM is %d",sum);
}
