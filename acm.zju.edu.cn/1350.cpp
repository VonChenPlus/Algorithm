#include<stdio.h>

int show(int m)
{
    int nu[m],j,k,count=0;
    for(j=0;j<m;j++)
        nu[j]=1;
    for(j=0;j<m;j++)
       if((j+1)%2==0)
            nu[j]=0;
    for(k=3;k<=m;k++)
        {
            for(j=0;j<m;j++)
                if((j+1)%k==0)
                    {
                        if(nu[j]==1)
                            nu[j]=0;
                        else
                            nu[j]=1;
                    }
        }
    for(j=0;j<m;j++)
        if(nu[j]==1)
            count++;
    return count;
}
int print(int n)
{
    int nu[n],i,j,open[n];
    for(i=0;i<n;i++)
        scanf("%d",&nu[i]);
    for(i=0;i<n;i++)
        open[i]=show(nu[i]);
    for(i=0;i<n;i++)
        printf("%d\n",open[i]);
    return 0;

}

int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
