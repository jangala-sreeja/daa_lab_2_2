#include<stdio.h>
int f[100];
int min=9999;
void swap(int a[],int l,int r)
{
	int temp;
	temp=a[l];
	a[l]=a[r];
	a[r]=temp;	
}
void permute(int a[],int l,int n,int m[n][n])
{
	int i;
	if(l==n)
	{
		int sum=0,i;
		for(i=0;i<n;i++)
		{
			sum=sum+m[i][a[i]];
		}
		if(sum<min)
		{
			min=sum;
			for(i=0;i<n;i++)
			{
				f[i]=a[i];
			}
		}
	}
	else
	{
		for(i=l;i<n;i++)
		{
			swap(a,l,i);
			permute(a,l+1,n,m);
			swap(a,l,i);
		}
	}
}
void main()
{
	int n,i,j;
	printf("enter the number of employees");
	scanf("%d",&n);
	char p[n];
	printf("Enter the String");
	scanf("%s",p);
	int a[n],m[n][n];
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		//	printf("enter the salary of %c doing %d job",p[j],j);
			printf("m[%d][%d]",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	permute(a,0,n,m);
	for(i=0;i<n;i++)
	{
		printf("%c->%d",p[i],f[i]);
	}
}
