#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 10;
bool vis[maxn][maxn];
struct Node
{
    int x, y;
    int step;
};
int x1, y1, x2, y2;
int dx[] = {1, 2, 2, 1, -1, -2, -1, -2};
int dy[] = {2, 1, -1, -2, 2, 1, -2, -1};
bool check(int x, int y)
{
    if (1 <= x && x <= 8 && 1 <= y && y <= 8)
        return true;
    else
        return false;
}
int bfs()
{
    queue<Node> q;
    q.push({x1, y1, 0});
    vis[x1][y1] = true;
    while (q.size())
    {
        Node nownode = q.front();
        q.pop();
        if (nownode.x == x2 && nownode.y == y2)
            return nownode.step;
        for (int i = 0; i < 8; i++)
        {
            int xx = nownode.x + dx[i];
            int yy = nownode.y + dy[i];
            int step = nownode.step + 1;
            if (vis[xx][yy] == false && check(xx, yy))
            {
                q.push({xx, yy, step});
                vis[xx][yy] = true;
            }
        }
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs();
    return 0;
}