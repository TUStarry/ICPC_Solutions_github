#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
const int N = 8;
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
char cc[N][N + 1], visited[N][N]; 
int qu[N * N], n, i_, j_, ans = 0;
 
void dfs(int k, int head, int cnt) 
{
	int ij, i, j, h, cnt_;
 
	if (k == 0) 
	{
		ans++;
		return;
	}
	if (cnt == 0) return;
	dfs(k, head + 1, cnt - 1);
	ij = qu[cnt--, head++], i = ij / n, j = ij % n;
	cnt_ = cnt;
	for (h = 0; h < 4; h++) 
	{
		int i1 = i + di[h], j1 = j + dj[h];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && (i1 > i_ || i1 == i_ && j1 >= j_) && !visited[i1][j1] && cc[i1][j1] == '.')
			visited[i1][j1] = 1, qu[head + cnt++] = i1 * n + j1;
	}
	dfs(k - 1, head, cnt);
	while (cnt-- > cnt_) 
	{
		int ij1 = qu[head + cnt], i1 = ij1 / n, j1 = ij1 % n;
		visited[i1][j1] = 0;
	}
}
 
int main() 
{
	int k; 
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", cc[i]);
		
	for (i_ = 0; i_ < n; i_++)
	{
		for (j_ = 0; j_ < n; j_++)
		{
			if (cc[i_][j_] == '.') //如果可以走 
			{
				qu[0] = i_ * n + j_;
				visited[i_][j_] = 1;
				dfs(k, 0, 1);
				visited[i_][j_] = 0;
			}				
		}
	}
	printf("%d\n", ans);
	return 0;
}