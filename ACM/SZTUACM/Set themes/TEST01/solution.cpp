#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 0;
int mp[105][105];
int main()
{
    //  freopen("01.in", "r", stdin);
    //  freopen("01.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(mp, 0, sizeof(mp));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                scanf("%d", &mp[i][j]);
        for (int i = n - 1; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                mp[i][j] += max(mp[i + 1][j], mp[i + 1][j + 1]);
        printf("%d\n", mp[1][1]);
    }

    return 0;
}