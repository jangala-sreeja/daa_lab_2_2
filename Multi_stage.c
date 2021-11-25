#include<stdio.h>
void main()
{
	int n,i,j,min=0,st,k;
	printf("enter number of nodes");
	scanf("%d",&n);
	printf("enter the no of stages");
	scanf("%d",&st);
	int c[n],d[n],a[n][n],p[st];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	c[n-1]=0;
	d[n-1]=n-1;
	for(i=n-2;i>=0;i--)
	{
		min=999;
		for(k=i+1;k<n;k++)
		{
			if(a[i][k]!=0 && c[k]+a[i][k]<min)
			{
				min=a[i][k]+c[k];
				j=k;
			}
			d[i]=j;
			c[i]=min;
		}
	}
	p[0]=0;
	p[st-1]=n-1;
	for(i=1;i<st-1;i++)
	{
		p[i]=d[p[i-1]];
	}
	printf("the cost is %d\n",c[0]);
	printf("path is ");
	for(i=0;i<st;i++)
	{
		printf("%d",p[i]);
	}
}
