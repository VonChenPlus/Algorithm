#include<stdio.h>
#define N 10000
int main()
{
    int i;
    float n,sum;
    scanf("%f",&n);
    while(n!=0.00)
        {   sum=0.00;
            for(i=2;i<N;i++)
                {
                    sum+=1/(float)i;
                    if(sum>=n)
                    {printf("%d card(s)\n",i-1);break;}
                }
                scanf("%f",&n);
        }
    return 0;
}
