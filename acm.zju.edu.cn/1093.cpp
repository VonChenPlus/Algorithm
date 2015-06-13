#include<stdio.h>
#include<stdlib.h>

#define N 200

typedef struct node
{
	int length;
	int broad;
	int high;
}trunk;

int best[N];
int temp[N];

int compar(const void *a,const void *b)
{
	trunk *aa=(trunk *)a,*bb=(trunk *)b;
	if((*aa).length>(*bb).length) return -1;
	if((*aa).length==(*bb).length) return 0;
	return 1;
}


int search(trunk box[],int js)
{
	int i,j,max;
	best[0]=box[0].high;
	for(i=1;i<js;i++)
	{
		max=0;
		for(j=0;j<i+1;j++)
		{
			
			if(box[j].length>box[i].length && box[j].broad>box[i].broad && max<best[j])
				max=best[j];
		}
		best[i]=max+box[i].high;
	}
	max=0;
	for(i=0;i<js;i++)
		if(max<best[i])
			max=best[i];
	return max;
}

int main()
{
	trunk box[N];
	int n,i;
	int a1,a2,a3;
	int js=0;
	int temp=0;
	while(scanf("%d",&n)!=EOF && n)
	{
		temp++;
		js=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&a1,&a2,&a3);
			box[js].length=a1;
			box[js].broad=a2;
			box[js].high=a3;
			js++;
			box[js].length=a1;
			box[js].broad=a3;
			box[js].high=a2;
			js++;
			box[js].length=a2;
			box[js].broad=a1;
			box[js].high=a3;
			js++;
			box[js].length=a2;
			box[js].broad=a3;
			box[js].high=a1;
			js++;
			box[js].length=a3;
			box[js].broad=a1;
			box[js].high=a2;
			js++;
			box[js].length=a3;
			box[js].broad=a2;
			box[js].high=a1;
			js++;
		}
		qsort(box,js,sizeof(trunk),compar);
		printf("Case %d: maximum height = %d\n",temp,search(box,js));
	}
	return 0;
}
