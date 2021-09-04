#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
inline ll power(ll a, ll b, ll p = 1e9 + 7)
{
    ll ans = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << power(a, b, c) << endl;
    }
    return 0;
}