#include <stdio.h>
#include <cmath>

int euler(int n)
{
    int ret = 1, i;
    for (i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            n /= i;
            ret *= i - 1;
            while (n%i == 0)
            {
                n /= i;
                ret *= i;
            }
        }
    }
    if (n>1)
        ret *= n - 1;
    return ret;
}

int main()
{
    int n, m, k, i, j;
    long long sum;
    while (~scanf("%d", &n))
    {
        m = sqrt((double) n);
        for (sum = 0, i = 1; i <= m; i++)
        {
            if (i*i == n && (!(n%i)))
            {
                sum += euler(i)*i;
                break;
            }

            if (!(n%i))
            {
                k = n / i;
                sum += euler(k)*i;
                sum += euler(i)*k;
            }
        }

        printf("%I64d\n", sum);
    }
}