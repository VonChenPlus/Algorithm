#include<stdio.h>
int print(int n)
{
    if(n<3) return 0;
    if(n==3)
        return 1;
   if(n>3)
        return print(n/2)+print((n+1)/2);
}
int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
        {
            t=print(n);printf("%d\n",t);
        }
    return 0;
}

