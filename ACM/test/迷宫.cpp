#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 6;
bool vis[maxn][maxn], mp[maxn][maxn];
int n, m, t, tempx, tempy, tot = 0;
int stx, sty, edx, edy;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (x == edx && y == edy)
    {
        tot++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!vis[xx][yy] && mp[xx][yy])
        {
            vis[xx][yy] = true;
            dfs(xx, yy);
            vis[xx][yy] = false;
        }
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &stx, &sty, &edx, &edy);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = true;
    vis[stx][sty] = true;
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d", &tempx, &tempy);
        mp[tempx][tempy] = false;
    }
    dfs(stx, sty);
    cout << tot;
    return 0;
}