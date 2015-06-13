#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1000000;

short Num[maxn + 1];
int m;

bool check(int x)
{
    int cnt = 0;
    for (int i = x; i <= m && cnt<2; i += x)
        cnt += Num[i];
    return cnt>1;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    memset(Num, 0, sizeof(Num));
    m = 0;

    while (n--)
        scanf("%d", &x), Num[x]++, m = max(m, x);

    for (int i = m; i; i--)
    {
        if (check(i))
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}