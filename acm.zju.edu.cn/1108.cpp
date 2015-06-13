#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000

int f[N];

typedef struct node
{
	int head;
	int trail;
	int index;
	int pre;
}mouse;

int compar(const void *a,const void *b)
{
	mouse *aa=(mouse *)a,*bb=(mouse *)b;
	if((*aa).trail>(*bb).trail) return 1;
	if((*aa).trail==(*bb).trail) return 0;
	return -1;
}

void search(mouse array[],int n)
{
	int max,i,j;
	for(i=0;i<n;i++)
	{
		max=0;
		for(j=0;j<i;j++)
			if(array[i].head<array[j].head && array

[i].trail>array[j].trail)
				if(max<f[j])
				{
					max=f[j];
					array[i].pre=j;
				}
		f[i]=max+1;
	}
}

int main()
{
	mouse array[N];
	int i=0,max=0,j;
	while(scanf("%d%d",&array[i].head,&array[i].trail)!=EOF && 

array[i].head && array[i].trail)
	{
		array[i].index=i+1;
		array[i].pre=i+1;
		i++;
	}
	memset(f,0,N);
	qsort(array,i,sizeof(mouse),compar);
	search(array,i);
	for(j=1;j<i;j++)
	{
		if(f[j]>f[max])
			max=j;
	}
	while(array[max].pre!=array[max].index)
	{
		printf("%d\n",array[max].index);
		max=array[max].pre;
	}
	printf("%d\n",array[max].index);
	return 0;
}