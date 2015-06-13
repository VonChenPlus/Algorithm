#include<stdio.h>
int main()
{
  int n,a,b,c,t;
  while(scanf("%d",&n)!=EOF)
    {
        t=n;
        a=t%10;t=t/10;
        b=t%10;t=t/10;
        c=t%10;
        if(n==(a*a*a+b*b*b+c*c*c))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
