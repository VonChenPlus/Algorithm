#include<stdio.h>
#include<string.h>
int print(int n)
{
    char str[n][50],ch;
    int i,j,m,w=0,b[n];
   for(i=0;i<n;i++)
        {ch=getchar();
         j=0;
         while(ch!='\n')
          {
             str[i][j]=ch;
             j++;
             ch=getchar();
          }
          b[w]=j;
          w++;
        }
     w=0;
    for(i=0;i<n;i++)
       {j=b[w];
        for(m=0;m<j;m++)
           if(str[i][m]+1>90)
                str[i][m]=str[i][m]+1-26;
           else
                str[i][m]=str[i][m]+1;
        w++;
       }
       w=0;
       for(i=0;i<n;i++)
       {
            printf("String #%d\n",i+1);
            j=b[w];
            for(m=0;m<j;m++)
               printf("%c",str[i][m]);
            printf("\n\n");
            w++;
       }
       return 0;
}

int main()
{
    int n;
    scanf("%d",&n);getchar();
    print(n);
    return 0;
}
