#include<stdio.h>
int issafe(int n,int a[n][n],int row,int col)
{
	int c,r;
	for(r=row-1,c=col-1;r>=0&&c>=0;c--,r--)
	{
		if(a[r][c]!=0)
		{
			return 0;
		}
	}
	r=row;
	for(c=col-1;c>=0;c--)
	{
		if(a[r][c]!=0)
		{
			return 0;
		}
	}
	for(c=col-1,r=row+1;r<n&&c>=0;r++,c--)
	{
		if(a[r][c]!=0)
		{
			return 0;
		}
	}
	return 1;
}
int nqueen(int n,int a[][n],int col)
{
	if(col>=n)
	{
		return 1;
	}
	else
	{
		int row;
		for(row=0;row<n;row++)
		{
			if(issafe(n,a,row,col))
			{
				a[row][col]=1;
				if(nqueen(n,a,col+1))
				{
					return 1;
				}
				else
					a[row][col]=0;
			}
		}
	}
	return 0;
}
void main()
{
	int n,row,col=0,i,j,k;
	printf("enter number of queens");
	scanf("%d",&n);
	int a[n][n];
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			a[row][col]=0;
		}
	}
	k=nqueen(n,a,0);
	for(i=0;i<n;i++)
		{
			printf("\n");
			for(j=0;j<n;j++)
			{
				printf("%d",a[i][j]);
			}
		}
}
