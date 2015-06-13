#include <stdio.h>

#define N 100

int array_max(int num[],int m)
{
	int i,max=-128;
	int sum=0;
	for(i=0;i<m;i++)
	{
		sum+=num[i];
		if(sum>max)
			max=sum;
		else
			if(sum<0)
				sum=0;
	}
	return max;
}

void compute(int num[N][N],int m)
{
	int i,j,k;int array[N];
	int sum=0,max=0;
	for(i=0;i<m;i++)
	{
		for(k=0;k<m;k++) array[k]=0;
		for(j=i;j<m;j++)
		{
			for(k=0;k<m;k++) array[k]+=num[j][k];
			sum=array_max(array,m);
			if(max<sum)
				max=sum;
		}
	}
	printf("%d\n",max);
}

int main()
{
	int n,i,j;int matrix[N][N];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&matrix[i][j]);
		compute(matrix,n);
	}
	return 0;
}