#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
const int inf = -0x3f3f3f3f;
ll arr[maxn], n;
char ch[maxn];
ll ans()
{
    for (int i = 1; i < n; i++)
    {
        if (ch[i] == '*')
        {
            int cur = i;
            while (arr[cur] == inf)
                cur--;
            while (arr[i + 1] == inf)
                i++;
            arr[cur] = arr[cur] * arr[i + 1];
            arr[i + 1] = inf;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (ch[i] == '+')
        {
            int cur = i;
            while (arr[cur] == inf)
                cur--;
            while (arr[i + 1] == inf)
                i++;
            arr[cur] = arr[cur] + arr[i + 1];
            arr[i + 1] = inf;
        }
        if (ch[i] == '-')
        {
            int cur = i;
            while (arr[cur] == inf)
                cur--;
            while (arr[i + 1] == inf)
                i++;
            arr[cur] = arr[cur] - arr[i + 1];
            arr[i + 1] = inf;
        }
    }
    return arr[1];
}
int main()
{
    cin >> n;
    {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        for (int i = 1; i < n; i++)
            cin >> ch[i];
        printf("%lld\n", ans());
    }
    return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
+ - + - + - + - +
*/