/*1205*/
#include<stdio.h>
#include<string.h>
int main()
{
   int n,w,i,j,num[2][101],a[101],b[2],sum;
   char str[2][101],ch,bh;


        for(i=0;i<2;i++)
            for(j=0;j<101;j++)
                num[i][j]=0;
        for(i=0;i<101;i++)
            a[i]=0;
   while(scanf("%s%s",str[0],str[1])!=EOF)
        {
            for(i=0;i<2;i++)
                for(j=0;j<101;j++)
                    num[i][j]=0;
            for(i=0;i<101;i++)
                a[i]=0;
            b[0]=strlen(str[0]);
            b[1]=strlen(str[1]);
            for(i=0;i<2;i++)
                for(j=0;j<b[i];j++)
                    {
                        if(str[i][j]>=48&&str[i][j]<=57)
                            num[i][j]=str[i][j]-48;
                        if(str[i][j]>=97&&str[i][j]<=106)
                            num[i][j]=str[i][j]-87;
                    }
            if(b[0]>b[1])
                n=b[0];
            else
                n=b[1];
            w=0;
            for(j=b[0]-1;j>=0;j--)
                {
                    a[w]=a[w]+num[0][j]+sum;sum=0;
                    if(a[w]>19)
                    {
                        sum=a[w]/20;
                        a[w]=a[w]%20;

                    }
                    w++;
                }
        while(sum!=0)
            {
                a[w]+=sum;
                if(a[w]>19)
                    {
                        sum=a[w]/20;
                        a[w]=a[w]%20;
                        w++;
                    }
                else sum=0;
                if(w>=n)
                    n++;
            }
        w=0;sum=0;
        for(j=b[1]-1;j>=0;j--)
            {
                a[w]=a[w]+num[1][j]+sum;sum=0;
                if(a[w]>19)
                    {
                        sum=a[w]/20;
                        a[w]=a[w]%20;

                    }
                w++;
            }
    while(sum!=0)
        {

            a[w]+=sum;
            if(a[w]>19)
                {
                    sum=a[w]/20;
                    a[w]=a[w]%20;
                    w++;
                }
            else sum=0;
            if(w>=n)
                n++;
        }
    for(i=n-1;i>=0;i--)
        {   if(a[i]>9)
                printf("%c",a[i]+87);
            else
                 printf("%d",a[i]);
        }
        printf("\n");
  }
  return 0;
}
