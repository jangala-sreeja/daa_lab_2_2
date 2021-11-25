#include<stdio.h>
#include<math.h>
struct point
{
	int x,y;
};
int brute(struct point p[],int st,int end)
{
	int i,j,min=999,d;
	for(i=st;i<end;i++)
	{
		for(j=i+1;j<end;j++)
		{
			d=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
			if(d<min);
				min=d;
		}
	}
	return min;
}
int min(int x,int y)
{
	return (x<y?x:y);
}
void swap(struct point p[],int i,int j)
{
	struct point temp;
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}
void qsort1(struct point p[],int st,int end)
{
	if(end-st>1)
	{
		int pivot=p[st].x;
		int i=st+1;
		int j=end;
		while(i<j)
		{
			while(p[i].x<pivot&&i<=end)
			{
				i++;
			}
			while(p[j].x>pivot&&j>=st)
			{
				j--;
			}
			if(i<j)
			{
				swap(p,i,j);
			}
		}
		swap(p,st,j);
		qsort1(p,i,j-1);
		qsort1(p,j+1,end);
	}
	else
	{
		if(st<end)
		{
			if(p[st].x>p[end].x)
			{
				swap(p,st,end);
			}
		}
	}
}
void qsort2(struct point p[],int st,int end)
{
	if(end-st>1)
	{
		int pivot=p[st].y;
		int i=st+1;
		int j=end;
		while(i<j)
		{
			while(p[i].y<pivot&&i<=end)
			{
				i++;
			}
			while(p[j].y>pivot&&j>=st)
			{
				j--;
			}
			if(i<j)
			{
				swap(p,i,j);
			}
		}
		swap(p,st,j);
		qsort2(p,i,j-1);
		qsort2(p,j+1,end);
	}
	else
	{
		if(st<end)
		{
			if(p[st].y>p[end].y)
			{
				swap(p,st,end);
			}
		}
	}
}
int stripmin(struct point stp[],int st,int end,int d)
{
	qsort2(stp,st,end);
	int i,j,l,min=999;
	for(i=st;i<end;i++)
	{
		for(j=i+1;j<end;j++)
		{
			if(abs(stp[j].y-stp[i].y)<d)
			{
				l=sqrt((stp[i].x-stp[j].x)*(stp[i].x-stp[j].x)+(stp[i].y-stp[j].y)*(stp[i].y-stp[j].y));
				if(l<min)
				{
					min=l;
				}
			}
		}
	}
	return min;
}
int closest(struct point p[],int st,int end)
{
	char x;
	int m,dl,dr,d,df;
	qsort1(p,st,end);
	if(end-st<=3)
	{
		//int d;
		return brute(p,st,end);
	}
	else
	{
		m=(st+end)/2;
		dl=closest(p,st,m);
		dr=closest(p,m+1,end);
		d=min(dl,dr);
		struct point strip[100];
		int j=0,i;
		for(i=0;i<end;i++)
		{
			if(abs(p[i].x-p[m].x)<d)
			{
				strip[j]=p[i];
				j++;
			}
		}
		df=min(d,stripmin(strip,0,j,d));
		return df;
	}
}
void main()
{
	struct point p[100];
	int n,i,df;
	printf("entere the number of points ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the coordinates of %d point",i+1);
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	df=closest(p,0,n-1);
	printf("%d",df);
}
