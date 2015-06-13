/*1526*/
#include<stdio.h>
#include<math.h>

int print(int n)
{
    int i,j;
    long num[n],nm[n];
    double sum;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    for(i=0;i<n;i++)
        {
            sum=0;
            for(j=1;j<=num[i];j++)
                sum+=(double)log10((double)j);
            nm[i]=(long)sum+1;
        }
    for(i=0;i<n;i++)
        printf("%ld\n",nm[i]);
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
