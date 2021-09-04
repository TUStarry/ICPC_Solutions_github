#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll arr[65];
int main()
{
    ll num = 1;
    for (int i = 1; i <= 62; i++)
    {
        num <<= 1;
        arr[i] = num;
        //cout << arr[i] << endl;
    }
    ll n;
    while (scanf("%lld", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] > n)
            {
                cout << i - 1 << endl;
                break;
            }
            if (arr[i] == n)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}