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
inline int gcd(int a, int b)
{
    if(a %b == 0) return b;
    else return (gcd(b, a%b));
}
inline int gcd2(int a, int b)
{
    return __gcd(a, b);
}
int main()
{
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            printf("gcd : %d\n",gcd(i, j));
            printf("gcd2 : %d\n",gcd2(i, j));
        }
    }
    return 0;
}