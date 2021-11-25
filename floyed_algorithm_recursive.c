#include<stdio.h>
floyd(int n,int m[][n],int p[][n])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			p[i][j]=m[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				p[i][j]=p[i][j] || (p[i][k]&&p[k][j]);
			}
		}
	}
}
void main()
{
	int n,i,j;
	printf("enter the no of nodes");
	scanf("%d",&n);
	int m[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("m[%d][%d]=",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	int p[n][n];
	floyd(n,m,p);
	printf("the path matrix is :-\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
	}
}
