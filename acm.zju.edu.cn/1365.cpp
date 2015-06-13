#include<stdio.h>
int main()
{
    int b,sum;
    char str[2][100],ch,dh;
    scanf("%s",str[0]);
    while(strcmp(str[0],"#")!=0)
        {  sum=0;
        while(strcmp(str[0],"0")!=0)
                {   scanf("%s",str[1]);
                    scanf("%d",&b);getchar();
                    dh=getchar();
                    if(dh=='F')
                        sum+=b*2;
                    if(dh=='B')
                        {if(b%2==0)
                            sum+=b+b/2;
                        else
                            sum+=b+b/2+1;   }
                    if(dh=='Y')
                        {
                            if(b>=500)
                                sum+=b;
                            else
                                sum+=500;
                        }
                    scanf("%s",str[0]);
                }
                printf("%d\n",sum);
                scanf("%s",str[0]);

            
        }
        return 0;
}
