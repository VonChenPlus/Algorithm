#include<stdio.h>

int print(int l)
{
    int q,m,n,j,i,num[100],w=0,sum=0,nb[100],sb[100],t,ww[100];
    for(i=0;i<100;i++)
        {nb[i]=0;ww[i]=0;   }
    char str[100][50];
    scanf("%d %d",&n,&m);getchar();
    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
            scanf("%c",&str[i][j]);
         getchar();
        }
    if(l!=1) printf("\n");
    for(i=0;i<m;i++)
        {sum=0;
         for(j=0;j<n-1;j++)
            {for(q=j;q<n;q++)
               {if(str[i][j]>str[i][q])
                        sum++;
               }
            }
         num[i]=sum;
        }
     for(i=0;i<n;i++)
        sb[i]=num[i];
     nb[0]=num[0];
    for(i=1;i<m;i++)
            for(j=0;j<=i;j++)
                {   /*w=0;  */
                    if(nb[j]>num[i])
                        {t=nb[j];nb[j]=num[i];num[i]=t;w=1;}
                    if(j==i&&w==1)
                       nb[j]=num[i];
                }
    /* for(i=0;i<m-2;i++)
        {w=1;
         for(j=m-1;j>=i;j--)
             if(nb[j+1]<nb[j])
                {t=nb[j+1];nb[j+1]=nb[j];nb[j]=t;w=0;}
             if(w) break;
         } */
    for(t=0;t<m;t++)
        {
            for(w=0;w<m;w++)
                if(nb[t]==sb[w])
                    {   if(ww[w]==1)
                            continue;
                        else
                            {for(i=0;i<n;i++)
                                printf("%c",str[w][i]);
                                ww[w]=1;
                                break;
                            }
                    }
                printf("\n");
        }
    return 0;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
         print(i);
    return 0;
}

