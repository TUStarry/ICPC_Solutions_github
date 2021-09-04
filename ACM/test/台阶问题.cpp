#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
int n, k;
const int mod = 100003;
int arr[maxn];
int main()
{
    scanf("%d%d", &n, &k);
    arr[0] = arr[1] = 1; 
    for (int i = 2; i <= n; i++)
        if (i <= k)
            arr[i] = arr[i - 1] * 2 % mod; 
        else
            arr[i] = arr[i - 1] * 2 - arr[i - k - 1], arr[i] %= mod; 
    cout << (arr[n] + mod) % mod << endl;                    
    return 0;
}