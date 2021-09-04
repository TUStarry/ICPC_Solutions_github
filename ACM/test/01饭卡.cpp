#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int dp[1005];
int arr[1005];
int main()
{
    int n, money;
    while (scanf("%d", &n) && n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        sort(arr + 1, arr + 1 + n);
        scanf("%d", &money);
        if (money < 5)
        {
            printf("%d\n", money);
            continue;
        }
        money -= 5;
        for (int i = 1; i < n; i++)
            for (int j = money; j >= arr[i]; j--)
                dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
        printf("%d\n", money + 5 - dp[money] - arr[n]);
    }
    return 0;
}
