#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int INF = (int)1 << 62;
int getLIS(vector<int> &a)
{
	int N = a.size();
	vector<int> dp(N, INF);
	for (int i = 0; i < N; ++i) {
		*upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin();
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	reverse(A.begin(), A.end());
	cout << getLIS(A) << endl;
}