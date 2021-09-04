#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5e5 + 5;
struct Tire
{
    int nxt[maxn][26], cnt;
    bool vis[maxn];
    void init()
    {
        memset(nxt, 0, sizeof(nxt));
        memset(vis, false, sizeof(vis));
        cnt = 1;
    }
    void insert(const string &s)
    { // 插入字符串
        int cur = 1;
        for (auto c : s)
        {
            if (!nxt[cur][c - 'a'])
                nxt[cur][c - 'a'] = ++cnt;
            cur = nxt[cur][c - 'a'];
        }
    }
    bool find_prefix(const string &s)
    {
        int cur = 1;
        for (auto c : s)
        {
            if (!nxt[cur][c - 'a'])
                return false;
            cur = nxt[cur][c - 'a'];
        }
        return true;
    }
} tr;
int main()
{

    return 0;
}