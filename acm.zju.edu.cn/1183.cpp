#include<stdio.h>

#define max 10000

int d[1001][1001];
int t[1001];

int main()
{
	int N,n;
	scanf("%d",&N);
	while(N--)
	{
		int l,c,Case=0;
		scanf("%d",&n);
		while(n)
		{
			scanf("%d%d",&l,&c);
			for(int i=1;i<=n;i++)
				scanf("%d",&t[i]);
			for(i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					d[i][j]=max;
			d[0][0]=0;
			for(i=0;i<n;i++)
			{
				if(d[i][n]!=max)
					break;
				for(int j=i;j<n;j++) 这个循环是为了更新d数组，使其变得更小
				{
					if(d[i][j]==max) //如果d[i][j]已经无法到达，那么再比他大的就更不可能到达了
						break;
					int x=l;
					for(int k=j+1;k<=n;k++)
					{
						x-=t[k];
						if(x<0)
							break;
						if(x==0)
							d[i+1][k]=d[i][j];
						else
							if(x>=1 && x<=10)
								d[i+1][k]=d[i][j]-c;
						else
							if(x>10)
								d[i+1][k]=d[i][j]+(x-10)*(x-10);
					}
				}
			}
			printf("Case %d:\n",++Case);
			printf("Minimum number of lectures: %d\n",i);
			printf("Total dissatisfaction index: %d",d[i][n]);
		}
	}
	return 0;
}
