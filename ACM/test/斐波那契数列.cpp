#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int f[maxn];
int main()
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 25; i++)
        f[i] = f[i - 1] + f[i - 2];
    int a, b;
    while(cin >> a >> b)
        cout << f[b] - f[a] << endl;
    return 0;
}