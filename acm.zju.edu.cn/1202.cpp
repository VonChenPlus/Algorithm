#include<stdio.h>

int print(int n)
{
    int s=1,num[n],i,j,sum=0,count;
    for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
    for(i=0;i<n-1;i++)
        {
            for(j=1;j<=num[i];j++)
                s=s*(sum-j+1)/j;
            sum=sum-num[i];
        }
    for(i=0;i<n-1;i++)
        {
          count=1;
          for(j=i+1;j<n;j++)
            if(num[i]==num[j])
                count++;
          s=s/count;
        }
        printf("%d\n",s);
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
        print(n);
    return 0;
}
