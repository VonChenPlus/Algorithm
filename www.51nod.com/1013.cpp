#include<stdio.h>

long long exp_mod(long long a, long long b, long long m)//ab mod m
{
    long long d = 1, t = a;
    while (b>0)
    {
        if (b & 0x1)d = (d*t) % m;
        b = b >> 1;
        t = (t*t) % m;
    }
    return d;
}

int main()
{
    long n;
    const long long a = 3;
    const long long b = 1000000007;
    long long result;
    while (scanf("%ld", &n) == 1)
    {
        long x = 500000004;
        result = (exp_mod(a, n + 1, b) - 1) % b;
        result *= x;
        result %= b;
        printf("%ld\n", result);
    }

    return 0;
}