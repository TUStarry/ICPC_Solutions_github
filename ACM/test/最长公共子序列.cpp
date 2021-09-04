#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int dp[maxn][maxn];
string str1, str2;
int main()
{
    while (cin >> str1 >> str2)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= str1.length(); i++)
            for (int j = 1; j <= str2.length(); j++)
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        printf("%d\n", dp[str1.length()][str2.length()]);
    }
    return 0;
}