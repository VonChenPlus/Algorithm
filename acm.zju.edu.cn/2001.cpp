#include<stdio.h>
#include<string.h>
int print(int n)
{
    int i,j,m[n],b[n][20],max,s,sum[n];
    char str1[n][20],str2[n][20];
    for(i=0;i<n;i++)
        for(j=0;j<20;j++)
            b[i][j]=0;
    for(i=0;i<n;i++)
        {scanf("%s %s",str1[i],str2[i]);getchar();}
    for(i=0;i<n;i++)
        {
            m[i]=strlen(str1[i]);
            if(m[i]<strlen(str2[i]))
                m[i]=strlen(str2[i]);
            s=0;
            for(j=0;j<m[i];j++)
                {

                    if(str1[i][j]!='\0') {b[i][j]=str1[i][j]-48+s;s=0;}
                    if(str2[i][j]!='\0') b[i][j]+=str2[i][j]-48+s;
                    if(b[i][j]>9)
                        {
                            s=b[i][j]/10;
                            b[i][j]=b[i][j]%10;
                        }
                    else s=0;
                }
            if(s!=0)
                {m[i]++;b[i][j]=s;}
        }
        for(i=0;i<n;i++)
           {s=0;
           for(j=0;j<m[i];j++)
                {   if(b[i][j]==0)
                        {
                            if(s==1)
                                printf("%d",b[i][j]);
                            else
                                continue;
                        }
                    else
                        {s=1;printf("%d",b[i][j]);}
                }
             printf("\n");
           }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
