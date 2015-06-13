#include<stdio.h>
int main()
{
    int i,a[100],n,base=0,t,sum;
    scanf("%d",&n);
    while(n!=0)
    {
       base=0;
       sum=0;
       for(i=0;i<n;i++)
            scanf("%d",&a[i]);
       i=0;
       while(i<n)
       {
           t=a[i];
           if(t>base)
            sum+=(t-base)*6+5;
           else
            sum+=(base-t)*4+5;
           base=t;
           i++;
       }
       printf("%d\n",sum);
       scanf("%d",&n);
    }

    return 0;
}
