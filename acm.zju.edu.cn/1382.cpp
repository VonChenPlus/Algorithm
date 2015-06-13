#include<stdio.h>
int main()
{
    int i,d,num[10],m[10][2],o,p,mid;
    scanf("%d",&d);
    for(i=0;i<d;i++)
        scanf("%d",&num[i]);
    for(i=0;i<d;i++)
        {
            mid=num[i];
            p=0;
            while(mid%2==0&&(mid!=0))
                {
                    mid=mid/2;
                    p++;
                }
            o=mid;

            m[i][0]=o;
            m[i][1]=p;
        }
    for(i=0;i<d;i++)
        printf("%d %d\n",m[i][0],m[i][1]);
    return 0;
}
