#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int n, m, tot = 0;
int head[maxn], ver[maxn], edge[maxn], nxt[maxn], dist[maxn];
bool vis[maxn];
void addE(int x, int y, int z){
    ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}
void dijkstra(int st, int ed){
    for(int i=0;i<maxn;i++) dist[i] = inf;
    for(int i=0;i<maxn;i++) vis[i] = false;
    dist[st] = 1;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0,st));
    while(q.size())
    {
        int x = q.top().second;q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(int i=head[x];i;i=nxt[i])
        {
            int y = ver[i], z = edge[i];
            //if()
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m))
    {

    }
    return 0;
}