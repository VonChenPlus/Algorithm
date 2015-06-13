#include<stdio.h>

int print(int n)
{
    int i,num[n][2],ss[n][2];
    for(i=0;i<n;i++)
        scanf("%d %d",&ss[i][0],&ss[i][1]);
    for(i=0;i<n;i++)
        {   if(ss[i][0]<ss[i][1])
                num[i][0]=-1;
            else
                {
                    num[i][0]=(ss[i][0]+ss[i][1])/2;
                    num[i][1]=(ss[i][0]-ss[i][1])/2;
                    if((num[i][0]+num[i][1])!=ss[i][0]||(num[i][0]-num[i][1])!=ss[i][1])
                        num[i][0]=-1;
                }
        }
    for(i=0;i<n;i++)
        {
            if(num[i][0]==-1)
                printf("impossible\n");
            else
                printf("%d %d\n",num[i][0],num[i][1]);
        }
    return 0;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        print(n);
    return 0;
}
