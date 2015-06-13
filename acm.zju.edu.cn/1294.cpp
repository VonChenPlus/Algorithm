/*1294*/
#include<stdio.h>
int main()
{
    int a[10000][2],i=0,j,n,sub;
    while((scanf("%d %d",&a[i][0],&a[i][1])!=EOF)&&(a[i][0]!=0))
        {
            i++;
        }
     n=i;
    for(i=0;i<n;i++)
        {
            if(a[i][0]==a[i][1])
                printf("Hole #%d\nPar.\n",i+1);
            else if(a[i][0]>a[i][1])
                {
                    if(a[i][1]==1)
                        printf("Hole #%d\nHole-in-one.\n",i+1);
                    else
                        {
                            sub=a[i][0]-a[i][1];
                            switch(sub)
                            {
                                case 1: printf("Hole #%d\nBirdie.\n",i+1);break;
                                case 2: printf("Hole #%d\nEagle.\n",i+1);break;
                                case 3: printf("Hole #%d\nDouble Eagle.\n",i+1);break;
                            }
                        }
                }
            else
                {
                    sub=a[i][1]-a[i][0];
                    if(sub==1)
                        printf("Hole #%d\nBogey.\n",i+1);
                    else
                        printf("Hole #%d\nDouble Bogey.\n",i+1);

                }
       /* if(i!=n-1) */
            printf("\n");
        }
        return 0;
}
