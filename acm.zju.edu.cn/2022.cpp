#include<stdio.h>
int print(long n)
{
    long num[n],nm[n],t,sum;
    int i,j;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    for(i=0;i<n;i++)
        {   t=num[i];sum=0;
            while(t/5!=0)
            {
                sum+=t/5;
                t=t/5;
            }
            nm[i]=sum;
        }
    for(i=0;i<n;i++)
        printf("%ld\n",nm[i]);
    return 0;
}
int main()
{
    long n;
    scanf("%ld",&n);
    print(n);
    return 0;
}
