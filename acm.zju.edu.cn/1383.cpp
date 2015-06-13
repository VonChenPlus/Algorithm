#include<stdio.h>

int print(int d)
{
    int num[d][20],nu[d],i,b,j,sum,temp[d],count[d],w;
    for(i=0;i<d;i++)
        scanf("%d",&nu[i]);
    for(i=0;i<d;i++)
        {   j=0;
            sum=nu[i];
            while(sum!=0)
                {
                    b=sum%2;
                    sum=sum/2;
                    temp[j]=b;
                    j++;
                }
                count[i]=j;
            for(w=0;w<j;w++)
                num[i][w]=temp[w];
        }
        for(i=0;i<d;i++)
            {
                for(j=0;j<count[i];j++)
                    if(num[i][j]==1)
                        {
                            printf("%d",j);
                            if(j!=count[i]-1)
                                printf(" ");
                        }
                printf("\n");
            }
    return 0;
}
int main()
{
    int d;
    scanf("%d",&d);
    print(d);
    return 0;
}
