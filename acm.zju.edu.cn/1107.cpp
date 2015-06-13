//¼ÇÒä»¯ËÑË÷
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,k;
int map[105][105];
int f[105][105];
int main()
{
	int search(int r,int c);
	int i,j;
	while(scanf("%d%d",&n,&k)==2)
	{
		if(n==-1 && k==-1)
			break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
			}
			memset(f,-1,sizeof(f));
			printf("%d\n",search(1,1));
	}
	return 0;
}

int search(int r,int c)
{
	int r1,c1,l;
	int maxn=0;
	if(f[r][c]!=-1) return f[r][c];
	for(int i=1;i<=k;i++)
	{
		r1=r-i;
		if(r1>=1 && r1<=n && map[r][c]<map[r1][c])
		{
			f[r1][c]=search(r1,c);
		    if(f[r1][c]>maxn)
			  maxn=f[r1][c];
		}
		r1=r+i;
		if(r1<=n && r1>=1 && map[r][c]<map[r1][c])
		{
			f[r1][c]=search(r1,c);
		    if(f[r1][c]>maxn)
				maxn=f[r1][c];
		}
		c1=c-i;
		if(c1>=1 && c1<=n && map[r][c]<map[r][c1])
		{
			f[r][c1]=search(r,c1);
			if(f[r][c1]>maxn)
				maxn=f[r][c1];
		}
		c1=c+i;
		if(c1>=1 && c1<=n && map[r][c]<map[r][c1])
		{
			f[r][c1]=search(r,c1);
			if(f[r][c1]>maxn)
				maxn=f[r][c1];
		}
	}
	return maxn+map[r][c];
}

