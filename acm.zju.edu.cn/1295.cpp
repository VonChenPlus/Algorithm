#include<stdio.h>
#include<string.h>
int print(int n)
{
    char str[n][70],ch;
    int i,j,b[n],m=0;
    for(i=0;i<n;i++)
        {ch=getchar();
         j=0;
         while(ch!='\n')
          {
             str[i][j]=ch;
             j++;
             ch=getchar();
          }
          b[m]=j-1;
          m++;
        }
        m=0;
       for(i=0;i<n;i++)
        {
          j=b[m];
         for(;j>=0;j--)
            printf("%c",str[i][j]);
            
         printf("\n");
         m++;
        }
    return 0;
}

int main()
{
    int i,n;
    scanf("%d",&n);getchar();
    print(n);
    return 0;
}
