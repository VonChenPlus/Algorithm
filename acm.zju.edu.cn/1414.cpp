/*1414*/
#include<stdio.h>
int print(int n)
{
    int x[n],y[n],i,num=0;
    for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    for(i=0;i<n;i++)
        {
              if ((x[i]==y[i])||(x[i]-y[i]==2))
                {
                    if(x[i]%2==0)
                         num=x[i]+y[i];
                    else
                        num=x[i]+y[i]-1;
                    printf("%d\n",num);

                }
            else
                printf("No Number\n");

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
