#include<stdio.h>

int main()
{
    int a,b,c,d;
    long int sum,aa;
    for(a=6;a<=200;a++)
        for(b=2;b<=a-3;b++)
            for(c=b+1;c<=a-2;c++)
                for(d=c+1;d<=a-1;d++)
                    {
                       sum=b*b*b+c*c*c+d*d*d;
                       aa=a*a*a;
                       if(sum==aa)
                            printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                       else
                            continue;
                    }
    return 0;
}
