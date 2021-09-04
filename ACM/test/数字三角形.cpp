#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 105;
int mp[105][105];
int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
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
