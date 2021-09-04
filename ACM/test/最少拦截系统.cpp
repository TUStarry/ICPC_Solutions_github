#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int dp[maxn];
int arr[maxn];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans = -inf;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            dp[i] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        for (int i = 1; i <= n; i++)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}