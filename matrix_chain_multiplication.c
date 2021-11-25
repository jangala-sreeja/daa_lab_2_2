#include<stdio.h>
int mcm(int a[],int i,int j)
{
	int k,min,temp;
	if(i>=j)
	{
		return 0;
	}
	else
	{
		min=9999;
		for(k=i;k<j;k++)
		{
			temp=mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
			if(temp<min)
				min=temp;
		}
		return min;
	}
}
void main()
{
	int n,i,j,result;
	printf("enter the length of array");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("a[%d]",i);
		scanf("%d",&a[i]);
	}
	i=1;
	j=n-1;
	result=mcm(a,i,j);
	printf("minimum number of multiplications are %d",result);
}
