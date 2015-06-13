//此程序看似贪心，实为动态规划的一种策略

#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct node
{
	int index;
	int start;
	int end;
}gene;

int compar(const void *a,const void *b)
{
	gene *aa=(gene *)a,*bb=(gene *)b;
	if((*aa).end>(*bb).end) return 1;
	if((*aa).end==(*bb).end) return 0;
	if((*aa).end<(*bb).end) return -1;
}

void search(gene link[],int n)
{
	int i,k=0;
	for(i=1;i<n;i++)
	{
		if(link[k].end<=link[i].start)
		{
			k=i;
			printf("%d ",link[i].index);
		}
	}
	printf("\n");
}

int main()
{
	gene link[N];
	int n,i;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			link[i].index=i+1;
			scanf("%d %d",&link[i].start,&link[i].end);
		}
		qsort(link,n,sizeof(gene),compar);
		printf("%d ",link[0].index);
		search(link,n);
	}
	return 0;
}