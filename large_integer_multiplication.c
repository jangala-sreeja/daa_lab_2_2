#include<stdio.h>
#include<math.h>
int size(int n1,int n2)
{
	int max,counter=0;
	if(n1<=n2)
	{
		max=n2;
	}
	else
		max=n1;
	while(max>0)
	{
		counter++;
		max/=10;
	}
	return counter;
}
double multiply(int n1,int n2)
{
	int nd,n,x,ao,a1,bo,b1,co,c1,c2;
	double ans=0;
	if(n1<=10||n2<=10)
		ans=n1*n2;
	else
	{
		n=size(n1,n2);
		nd=floor(n/2);
		double p=pow(10,nd);
		a1=n1/p;
		ao=n1%(int)p;
		b1=n2/p;
		bo=n2%(int)p;
		c2=multiply(a1,b1);
		co=multiply(ao,bo);
		c1=multiply((ao+a1),(bo+b1));
		ans=(c2*pow(10,2*nd)+((c1-c2-co)*pow(10,nd))+co);
	}
	return ans;
}
void main()
{
	int n1,n2;
	printf("enter the first largest number");
	scanf("%d",&n1);
	printf("enter the second largest number");
	scanf("%d",&n2);
	int ans=(int)multiply(n1,n2);
	printf("result: %d\n",ans);
}

