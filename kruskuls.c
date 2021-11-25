#include<stdio.h>
int p[100];
int find(int i)
{
	while(p[i])
	{
		i=p[i];
	}
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		p[j]=i;
		return 1;
	}
	return 0;
}
void main()
{
	int n,i,j,ne=1,min=999,a,b,u,v,mincost=0;
	printf("enter number of nodes");
	scanf("%d",&n);
	int m[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("m[%d][%d]",i,j);
			scanf("%d",&m[i][j]);
			if(m[i][j]==0)
			{
				m[i][j]=999;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		p[i]=0;
	}
	while(ne<n)
	{
		min=999;
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(m[i][j]<min)
				{
					min=m[i][j];
					a=i;
					b=j;
				}
			}
		}
		//printf("%d %d %d",min,a,b);
		
		u=find(a);
		v=find(b);
		if(uni(u,v))
		{
			printf("(%d,%d)-->%d",a,b,min);
			mincost=mincost+m[a][b];
			ne++;
		}
		m[a][b]=999;
		m[b][a]=999;
	}
	printf("\n %d",mincost);
}
