#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int winner;
int num[101];

void search(int a,int b,int n)
{
	if(b==1)
		if(a==1)
			winner=1;
		else
			winner=2;
	if(n<=100)
	{
	if(b%n==0 && winner!=1) 
	{
		num[n]=1;
		search(a,b/n,n+1);
	}
	if(num[n]!=1 && a%n==0 && winner!=1) search(a/n,b,n+1);
	if(winner!=1) search(a,b,n+1);
	}
}

void main()
{
	int n1,n2;int temp;
	while(scanf("%d %d",&n1,&n2)!=EOF)
	{
		for(int i=0;i<=100;i++)
			num[i]=0;
		winner=0;
		if(n1<n2)
		{
			temp=n1;
			n1=n2;
			n2=temp;	
		}
			search(n1,n2,2);
			if(winner==0) winner=1;
			if(winner==1)
			printf("%d\n",n1);
			else
				printf("%d\n",n2);
	}
}