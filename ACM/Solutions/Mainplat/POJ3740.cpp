#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 3628800 + 5;
int mp[20][305], m, n;
bool vis[310], flag;
bool judge() {
    for(int i = 1; i <= n; i++)
        if(!vis[i]) return false;
    return true;
}
bool check(int Row) {
    for(int i = 1; i <= n; i++)
        if(vis[i] && mp[Row][i]) return false; 
    for(int i = 1; i <= n; i++)
        if(mp[Row][i]) vis[i] = true; 
    return true;
}
void dfs(int col) {
    if(flag || col > m + 1) return;
    if(judge()) {
        printf("Yes, I found it\n");
        flag = true;
        return;
    }
    for(int i = col; i <= m && !flag; i++) {
        if(check(i)) {
            dfs(i + 1);
            for(int j = 1; j <= n; j++) 
                if(mp[i][j]) vis[j] = false;
        }
    }
}

int main() 
{
    while(scanf("%d%d", &m, &n) != EOF) 
    {
        flag = false;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &mp[i][j]);
        dfs(1);
        if(!flag) printf("It is impossible\n");
    }
    return 0;
}

