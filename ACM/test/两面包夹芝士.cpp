#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10000;
int arr[maxn];
int brr[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        cin >> brr[i];
    sort(arr + 1, arr + n + 1);
    sort(brr + 1, brr + n + 1);
    int ans = brr[1] - arr[n] + 1;
    if(ans >= 0) cout << ans;
    else cout << 0;
    return 0;
}
