#include<stdio.h>
#include<math.h>
int main()
{
    float n[10000],a,b,c;
    int t,i=0;
    char ch[10000];
    scanf("%f %f %f",&a,&b,&c);
    while(a!=0&&b!=0&&c!=0)
    {
       if(a==-1)
            {
              if(b>=c)
                ch[i]='q';
              else
              {
                a=sqrt(c*c-b*b);
                ch[i]='a';
                n[i]=a;
              }
              i++;
            }
       else if(b==-1)
            {
                if(a>=c)
                    ch[i]='q';
                else
                    {
                        b=sqrt(c*c-a*a);
                        ch[i]='b';
                        n[i]=b;
                    }
                i++;
            }
       else
            {
                c=sqrt(a*a+b*b);
                ch[i]='c';
                n[i]=c;
                i++;
            }
       scanf("%f %f %f",&a,&b,&c);
    }
     t=i;
     for(i=0;i<t;i++)
        if(ch[i]=='q')
           {
                printf("Triangle #%d\n",i+1);
                printf("Impossible.\n\n");
           }
        else
            {
              printf("Triangle #%d\n",i+1);
              printf("%c = %.3f\n\n",ch[i],n[i]);
            }
    return 0;
}
