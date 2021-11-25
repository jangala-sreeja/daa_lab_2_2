#include<stdio.h>
#include<string.h>
void main()
{
	int m,n,i,j,f=0;
	char s1[20],s2[20];
	printf("enter the length of string");
	scanf("%d",&m);
	printf("enter the string");
	scanf("%s",s1);
	printf("enter the length of searching string");
	scanf("%d",&n);
	printf("enter the searching string");
	scanf("%s",s2);
	for(i=0;i<m-n+1;i++)
	{
		f=0;
		for(j=i;j<i+n;j++)
		{
			if(s1[j]==s2[j-i])
			{
				f++;
			}
		}
		if(f==n)
		{
			printf("the string was found at %d - %d",i,i+n-1);
		}
	}
}
