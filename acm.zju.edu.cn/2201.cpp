#include<stdio.h>
int print(int n)
{
    int a[n][2],i;
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    for(i=0;i<n;i++)
        if(a[i][0]>=a[i][1])
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
