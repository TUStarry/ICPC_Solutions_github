#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    };
} fast_ios_;

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
        int64 cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cnt += (a[i] + mid - 1) / mid - 1;
        }
        // trace(mid, cnt);
        if (cnt > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    printf("%d\n", high);
    return 0;
}
