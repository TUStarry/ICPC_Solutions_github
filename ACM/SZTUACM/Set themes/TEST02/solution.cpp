#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
void solution()
{
    freopen("15.in", "r", stdin);
    freopen("15.out", "w", stdout);
}
const int maxn = 5005, INF = 0x3f3f3f3f;
int a[maxn], f[maxn];
int n, ans = -INF;
int main()
{
    // solution();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ans = -INF;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            f[i] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i]);
        printf("%d\n", ans);
    }

    return 0;
}