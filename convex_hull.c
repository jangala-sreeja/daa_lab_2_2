#include<stdio.h>
struct coord
{
	int x;
	int y;
}c[20];
void main()
{
	int h,b,m,i,j,k,l,q=0,a[20],n,f1=0,f2=0;
	printf("enter the number of coordinates");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the %d coordinates",i);
		scanf("%d %d",&c[i].x,&c[i].y);
	}
	for(i=0;i<n;i++)
	{
		a[i]=-1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			h=c[j].y-c[i].y;
			b=c[i].x-c[j].x;
			m=c[i].x*c[j].y-c[j].x*c[i].y;
			f1=0;
			for(k=0;k<n;k++)
			{
				if(k!=i&&k!=j)
				{
					if(h*c[k].x+b*c[k].y<m)
					{
						f1++;
					}
				}
			}
			if(f1==0||f1==n-2)
			{
				f2=0;
				for(l=0;l<n;l++)
				{
					if(a[l]==i)
					{
						f2=1;
						break;
					}
				}
				if(f2==0)
				{
					a[q]=i;
					q++;
				}
				f2=0;
				for(l=0;l<n;l++)
				{
					if(a[l]==j)
					{
						f2=1;
						break;
					}
				}
				if(f2==0)
				{
					a[q]=j;
					q++;
				}
			}
		}
	}
	for(i=0;i<q;i++)
	{
		printf("(%d,%d)",c[a[i]].x,c[a[i]].y);
		printf("\n");
	}
}
