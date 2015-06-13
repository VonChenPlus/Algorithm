//此题为LCS问题的变形，满足最优子结构性质，我们需要求子问题的最优解
//可归纳为以下情况
//1.如果str1[i]与str2[j]各自都以自己的字符来填充，则com[i-1][j-1]加上他们两个碱基的数值
//2.如果str1[i]与‘-’对应，则com[i][j-1]加上它与‘-’对应的数值
//3.如果str2[j]与‘-’对应，则com[i-1][j]加上它与‘-’对应的数值
//公式归纳如下：
//com[i][j]=max（com[i-1][j-1]+score[str1[i-1]][str2[j-1]],com[i][j-1]+score[4][str2[j-1]]，
//com[i][j],com[i-1][j]+score[str1[i-1]][4]）
//即求字符串str1第i位与str2第j位的最优解

#include <stdio.h>

#define N 100

int com[N][N];
int score[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int m,n;

int trans(char s)
{
	switch(s)
	{
	case 'A':return 0;
	case 'C':return 1;
	case 'G':return 2;
	case 'T':return 3;
	}
}

int max(int x,int y)
{
	return x>y?x:y;
}

void search(char str1[N],char str2[N])
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			com[i][j]=max(com[i-1][j-1]+score[str1[i-1]][str2[j-1]],com[i][j-1]+score[4][str2[j-1]]);
			com[i][j]=max(com[i][j],com[i-1][j]+score[str1[i-1]][4]);
		}
}


int main()
{
	int k;char str1[N],str2[N];
	scanf("%d",&k);
	while(k--)
	{
		com[0][0]=0;
		scanf("%d",&m);
		scanf("%s",&str1);
		for(int i=0;i<m;i++)
		{
			str1[i]=trans(str1[i]);
			com[i+1][0]=score[str1[i]][4]+com[i][0];
		}
		scanf("%d",&n);
		scanf("%s",&str2);
		for(i=0;i<n;i++)
		{
			str2[i]=trans(str2[i]);
			com[0][i+1]=score[4][str2[i]]+com[0][i];
		}
		search(str1,str2);
		printf("%d\n",com[m][n]);
	}
    return 0;
}