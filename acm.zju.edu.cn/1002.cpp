/*深度算法*/
#include<stdio.h>

char map[5][5];
int max;

/*寻找该点是否可被标记为许可点*/
bool canput(char map[5][5],int x,int y)
{
	if(map[x][y]!='.')
		return 0;
	int i;
	for(i=x-1;i>=0;i--)
	{
		if(map[i][y]=='X')
			break;
		if(map[i][y]=='F')    //F代表被找到的许可点
			return 0;
	}
	for(i=y-1;i>=0;i--)
	{
		if(map[x][i]=='X')
			break;
		if(map[x][i]=='F')
			return 0;
	}
	return 1;
}

void dfs(char map[5][5],int n,int depth,int put)
{
	if(put>max)
		max=put;
	if(depth>=n*n)
		return;
	dfs(map,n,depth+1,put);
	int x=depth/n,y=depth%n;
	if(canput(map,x,y))
	{
		map[x][y]='F';
		put++;
		dfs(map,n,depth+1,put);
		map[x][y]='.';
		put--;
	}
}

int main()
{//freopen("input.txt","r",stdin);
	int i,n;
	while(scanf("%d",&n)!=EOF && n)
	{
		max=0;
		for(i=0;i<n;i++)
			scanf("%s",&map[i]);
		dfs(map,n,0,0);
		printf("%d\n",max);
	}
 return 0;
}