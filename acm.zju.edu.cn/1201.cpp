/*1201*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,n,num[50],res[50],sum,temp,w;
    char str;
    scanf("%d",&n);getchar();
    while(n!=0)
        {   for(i=0;i<n;i++)
                res[i]=0;
            str=getchar();
            for(i=0;i<n;i++)
                scanf("%d",&num[i]);

           if(str=='P')
           {
            for(i=1;i<=n;i++)
                {
                    sum=0;
                    for(j=0;j<n;j++)
                        {
                            if(i==num[j])
                                break;
                            if(i<num[j])
                                sum++;
                        }
                    res[i-1]=sum;
                }
            }
          else

         {
            for(i=n;i>=1;i--)
                  { j=i-1;
                    if(i==n)
                        res[0]=i;
                    else
                        if(num[j]==0)
                            {
                                for(k=n-i;k>0;k--)
                                    res[k]=res[k-1];
                                res[0]=i;
                            }
                        else
                            {
                                sum=0;
                                for(w=0;w<n-i;w++)
                                    {
                                        if(res[w]>i)
                                            sum++;
                                        if(sum==num[j])
                                            {
                                                for(k=n-i;k>w+1;k--)
                                                    res[k]=res[k-1];
                                                res[w+1]=i;
                                                 break;
                                            }
                                    }
                            }
              }
         }

          for(i=0;i<n;i++)
            {printf("%d",res[i]);
             if(i!=n-1)
             printf(" ");
            }
            printf("\n");

         scanf("%d",&n);getchar();
        }
    return 0;
}
