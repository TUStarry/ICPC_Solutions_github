#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define MAXN 100005
typedef long long ll;
ll dp[20];
int main()
{
	memset(dp, 0, sizeof(dp));
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i <= n; i++)
	{
		dp[1] = (dp[1] + (s[i] == 'c')) % MOD;
		dp[2] = (dp[2] + (s[i] == 'h') * dp[1]) % MOD;
		dp[3] = (dp[3] + (s[i] == 'o') * dp[2]) % MOD;
		dp[4] = (dp[4] + (s[i] == 'k') * dp[3]) % MOD;
        dp[5] = (dp[5] + (s[i] == 'u') * dp[4]) % MOD;
        dp[6] = (dp[6] + (s[i] == 'd') * dp[5]) % MOD;
        dp[7] = (dp[7] + (s[i] == 'a') * dp[6]) % MOD;
        dp[8] = (dp[8] + (s[i] == 'i') * dp[7]) % MOD;
	}
    cout<<dp[8];
	return 0;
}
