#include<stdio.h>
#include<string.h>

#define N 5

int triangles[N][N];
int success;
int fix[N][N];
int sign[N*N];
int n;

int canput(int x,int y)
{
	if(x-1>0)
		if(triangles[fix[x][y]][4]!=triangles[fix[x-1][y]][2])
			return 0;
	if(y-1>0)
		if(triangles[fix[x][y]][1]!=triangles[fix[x][y-1]][3])
			return 0;
	return 1;
}

void search(int pos,int x,int y)
{
	if(pos>n*n)
	{
		success=1;
		return;
	}
	if(!success)
	for(int i=1;i<=n*n;i++)
	{
		if(sign[i]==0)
		{
			sign[i]=1;
			fix[x][y]=i;
			if(canput(x,y))
			{
				if(y+1>n)
				search(pos+1,x+1,1);
				else
					search(pos+1,x,y+1);
			}
			sign[i]=0;
		}
	}
}

int main()
{
	int Case=0;
	while(scanf("%d",&n) && n)
	{
		for(int i=1;i<=n*n;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&triangles[i][j]);
		success=0;
		memset(fix,0,sizeof(fix));
		memset(sign,0,sizeof(sign));
		search(1,1,1);
		if(success==1)
			printf("Game %d: Possible\n\n",++Case);
		else
			printf("Game %d: Impossible\n\n",++Case);
	}
}