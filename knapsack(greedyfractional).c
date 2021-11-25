#include<stdio.h>
struct item
{
	float wt;
	float val;
	float pbyw;
};
void main()
{
	int n,i,j,p,W;
	float max,t=0;
	struct item temp;
	printf("enter the bag weight");
	scanf("%d",&W);
	printf("enter the count of items");
	scanf("%d",&n);
	struct item b[n];
	for(i=0;i<n;i++)
	{
		printf("enter the weight and value of %d item",i+1);
		scanf("%f %f",&b[i].wt,&b[i].val);
		b[i].pbyw=(b[i].val/b[i].wt);
	}
	for(i=0;i<n-1;i++)
	{
		max=b[i].pbyw;
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j].pbyw>max)
			{
				max=b[j].pbyw;
				p=j;
			}
		}
		if(p!=i)
		{
			temp=b[p];
			b[p]=b[i];
			b[i]=temp;
		}
	}
	printf("items included in the bag are\n");
	for(i=0;i<n;i++)
	{
		if(b[i].wt<W)
		{
			t=t+b[i].val;
			W=W-b[i].wt;
			printf("wt=%f\tval=%f\n",b[i].wt,b[i].val);
		}
		else
		{
			t=t+W*b[i].pbyw;
			printf("wt=%f\tval=%f\n",b[i].wt,b[i].val);
			break;
		}
	}
	printf("maximum profit is %f",t);
}

