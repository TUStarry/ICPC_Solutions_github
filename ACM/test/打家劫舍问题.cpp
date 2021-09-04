#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10000;
int dp[maxn];
int nums[maxn];
int n;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i<n;i++) cin>>nums[i];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            printf("%d\n", dp[n-1]);
    }
    return 0;
}
