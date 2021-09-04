#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int low = 1, high = 1e9;
    while (low != high)
    {
        int mid = (low + high) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += (a[i] + mid - 1) / mid - 1;
        if (cnt > m)
            low = mid + 1;
        else
            high = mid;
    }
    printf("%d\n", high);
    return 0;
}
