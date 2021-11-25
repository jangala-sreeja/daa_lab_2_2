#include<stdio.h>
#include<math.h>
struct coord
{
	int x,y;
}c[20];
void main()
{
	int n,ind1,ind2,min=9999;
	int i,j;
	double d;
	printf("enter the number of coordinates");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the %d coordinates",i);
		scanf("%d %d",&c[i].x,&c[i].y);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			d=sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y));
			if(d<min)
			{
				min=d;
				ind1=i;
				ind2=j;
			}		
		}
	}
	printf("The closest pair is (%d,%d) and (%d,%d)",c[ind1].x,c[ind1].y,c[ind2].x,c[ind2].y);
}
