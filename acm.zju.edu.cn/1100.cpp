#include<stdio.h>
#include<string.h>

double ans,f[12][2049];
int height,wide;
bool record[13];
bool dfs_jieya(int start) //恢复前面一行的状态（注意：这些状态是相对固定的）
{
	if(start==0) return true;
	int i;
	for(i=wide-1;i>=0;i--)
	{
		if(record[i]==false && start-(1<<i)>=0)
		{
			record[i]=true;
			if(dfs_jieya(start-(1<<i)))
				return true;
			record[i]=false;
		}
	}
	return false;
}

void construct(int s,int j,int k,int begin)
//f[s][j]-->f[s+1][k];
{
	int i;
	for(i=begin;i<=wide-1;i++)
	{
		if(record[i]==false)
		{
			if(i+1<=wide-1 && record[i+1]==false)
			{
				construct(s,j,k,i+2);
			}
			construct(s,j,k+(1<<i),i+1);
			return;
		}
	}
	f[s+1][k]+=f[s][j];
	return;
}

void construct_lastline(int j,int k,int begin)
//f[height][j]-->ans+=f[height][j]
{
	int i;
	for(i=begin;i<=wide-1;i++)
	{
		if(record[i]==false)
		{
			if(i+1<=wide-1 && record[i+1]==false)
			{
				construct_lastline(j,k,i+2);
			}
			return;
		}
	}
	ans+=f[height][j];
	return;
}

void solve()
{
	int i,j,k;
	memset(f,0,sizeof(f));
	memset(record,false,sizeof(record));
	f[1][0]=1;
	construct(1,0,0,0);//为了找出满足状况的第二行
	for(i=2;i<=height-1;i++)
	{
		for(j=0;j<=1<<wide;j++)
		{
			if(f[i][j]>0)
			{
				memset(record,false,sizeof(record));
				if(dfs_jieya(j)==false)
				{
					printf("error!::j=%d\n",j);
					return;
				}
				construct(i,j,0,0);
			}
		}
	}
	for(j=0;j<=1<<wide;j++)
	{
		if(f[height][j]>0)
		{
          memset(record,false,sizeof(record));
		  dfs_jieya(j);
		  construct_lastline(j,0,0);
		}
	}
	return;
}

int main()
{

	while(scanf("%d %d",&height,&wide)!=EOF && height && wide)
	{
		ans=0;
		solve();
		printf("%.0lf\n",ans);
	}
	return 0;
}
