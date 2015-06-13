#include<stdio.h>
int print(int w,int q)
{   int n,m,j,a,b,i=0,num[10000][2],count[10000],h,sum,res;
    for(j=0;j<10000;j++)
        count[j]=0;
    while(scanf("%d %d",&n,&m)!=EOF&&(n!=0||m!=0))
        {
            num[i][0]=n;num[i][1]=m;
            i++;
        }
    for(j=0;j<i;j++)
        for(a=1;a<num[j][0]-1;a++)
            for(b=a+1;b<num[j][0];b++)
                {
                    sum=a*a+b*b+num[j][1];
                    res=(int)sum/(a*b);
                    if(res*a*b==sum)
                        count[j]++;
                }
    for(j=0;j<i;j++)
        printf("Case %d: %d\n",j+1,count[j]);
     if(w!=q-1)
        printf("\n");
    return 0;
}
int main()
{
    int n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
       print(i,n);
    return 0;
}
