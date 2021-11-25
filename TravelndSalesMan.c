#include<stdio.h>
char main_string[100],final_string[100];
int min=9999;
void swap(char a[],int l,int r)
{
	char temp;
	temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}
void perm(char a[],int l,int r,int m[r][r] )
{
	int i;
	if(l==r)
	{
		printf("%s\n",a);
		int k=0,k1=0,sum=0,i,j;//k is temporary string index and k1 is for count.
		while(k1<r)
		{
			for(i=0;i<r;i++)
			{
				if(main_string[i]==a[k])
				{
					break;
				}
			}
			if(k!=r-1)
			{
				k++;
				k1=k;
			}
			else
			{
				k=0;
				k1++;
			}
			for(j=0;j<r;j++)
			{
				if(main_string[j]==a[k])
				{
					break;
				}
			}	
			sum=sum+m[i][j];
		}
		//printf("%d",sum);
		if(sum<min)
		{
			min=sum;
			for(i=0;i<r;i++)
			{
				final_string[i]=a[i];
			}
		}
	}
	else
	{
		for(i=l;i<r;i++)
		{
			swap(a,l,i);
			perm(a,l+1,r,m);
			swap(a,l,i);
		}
	}
}
void main()
{
	int l,r,i,j,n;
	printf("enter the length");
	scanf("%d",&n);
	char a[n];
	printf("enter the string");
	scanf("%s",a);
	int m[n][n];
	for(i=0;i<n;i++)
	{
		main_string[i]=a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter a[%d][%d]",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	perm(a,0,n,m);
	printf("\nThe shortest path is %s %d",final_string,min);
}
