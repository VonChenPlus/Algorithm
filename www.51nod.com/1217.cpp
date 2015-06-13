#include<iostream>  
#include<stdio.h>  
#include<cmath>  
#include<string.h>  
#include<algorithm>  
#include<queue>  
#include<stack>  

using namespace std;
int arr[5005], c[1000005], n;
bool used[1000005];
int main()
{
    int i, j, k, m;
    while (~scanf("%d%d", &n, &k))
    {
        for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
        sort(arr + 1, arr + 1 + n);
        memset(c, 0, sizeof(c));
        for (i = 1; i<n; i++)
            for (j = i; j <= n; j++)
                c[arr[j] - arr[i]]++;
        for (i = 1; i <= arr[n] + 1; i++)
        {
            m = 0;
            for (j = i; j <= 1000000; j += i)
            {
                m += c[j];
                if (m>k*(k + 1) / 2)
                    break;
            }
            if (j <= 1000000)
                continue;

            memset(used, false, sizeof(used));
            m = 0;
            for (j = 1; j <= n; j++)
            {
                if (used[arr[j] % i]) m++;
                used[arr[j] % i] = true;
                if (m>k)
                    break;
            }
            if (j > n)
                break;
        }
        printf("%d\n", i);
    }
    return 0;
}