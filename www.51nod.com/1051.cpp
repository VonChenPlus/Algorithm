#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int dp[501][501];
int maxsub(int n, int a [])
{
    int i, sum = 0, b = 0;
    for (i = 1; i <= n; i++)
    {
        if (b>0)b += a[i];
        else b = a[i];
        if (b>sum)sum = b;
    }
    return sum;
}

int main()
{
    int b[501];
    int m, n, i, k, j, sum, maxsum;

    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &dp[i][j]);
            }
        }

        maxsum = 0;
        for (i = 1; i <= n; i++)
        {
            memset(b, 0, sizeof(b));
            for (j = i; j <= n; j++)
            {
                for (k = 1; k <= m; k++)
                {
                    b[k] += dp[j][k];
                }

                sum = maxsub(m, b);
                if (sum>maxsum)
                    maxsum = sum;
            }
        }

        printf("%d\n", maxsum);
    }

    return 0;
}