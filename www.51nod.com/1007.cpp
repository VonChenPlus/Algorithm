#include <stdio.h>
#include <string.h>
#define len 64*400

int main()
{
    int a[len], d[len], i, j, n, sum;
    while (scanf("%d", &n) == 1)
    {
        memset(d, 0, sizeof(d));
        for (i = 0, sum = 0; i<n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for (i = 0; i<n; i++)
        {
            for (j = sum / 2; j >= a[i]; j--)
                if (d[j - a[i]] + a[i]>d[j]) d[j] = d[j - a[i]] + a[i];
        }
        printf("%d\n", sum - d[sum / 2] * 2);
    }
    return 0;
}