/*2109*/
#include<stdio.h>

int print(int m,int n)
{
    int a[n][2],i,j,w,sum0=0,sum=0;
    float  b[n],max,res=0;
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    for(i=0;i<n;i++)
       { b[i]=(float)a[i][0]/a[i][1];}
    for(i=0;i<n;i++)
        {sum0+=a[i][0];sum+=a[i][1];}
    if(m>sum)
        res+=(float)sum0;
    else
        while(m!=0)
            {
                max=0;
                for(i=0;i<n;i++)
                    {
                        if(max<b[i])
                            {max=b[i];w=i;}
                    }
                b[w]=0;
                if(m<=a[w][1])
                    {res=res+(float)a[w][0]*m/a[w][1];m=0;}
                else
                    {res+=a[w][0];m=m-a[w][1]; }
            }

    printf("%.3f\n",res);
    return 0;
}

int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)==2)
        {
            if(m==-1&&n==-1)
                break;
            print(m,n);
        }
    return 0;
}
