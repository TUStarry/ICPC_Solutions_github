#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 50050;
const int inf = 0x3f3f3f3f;
int n, m, s, t, tot = 1;
int maxflow, mincost;
int dis[maxn], head[maxn], incf[maxn], pre[maxn];//dis表示最短路，incf表示当前增广路上最小流量，pre表示前驱
bool vis[maxn];
struct Edge {
	int nxt, to, dis, flow;
}edge[maxn * 2];
void addE(int u, int v, int w, int dis) {
	edge[++tot].nxt = head[u];edge[tot].to = v;
    edge[tot].dis = dis;edge[tot].flow = w;head[u] = tot;
}
bool spfa() 
{
	queue <int> q;
	for(int i=0;i<maxn;i++) dis[i] = inf;
	for(int i=0;i<maxn;i++) vis[i] = 0;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	incf[s] = 1 << 30;
	while(!q.empty()) 
    {
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = edge[i].nxt) 
        {
			if(!edge[i].flow) continue;//没有剩余流量
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].dis) 
            {
				dis[v] = dis[u] + edge[i].dis;
				incf[v] = min(incf[u], edge[i].flow);//更新incf
				pre[v] = i;
				if(!vis[v]) vis[v] = 1, q.push(v);
			}
		}
	}
	if(dis[t] == inf) return 0;
	return 1;
}
void MCMF() 
{
	while(spfa()) {//如果有增广路
		int x = t;
		maxflow += incf[t];
		mincost += dis[t] * incf[t];
		int i;
		while(x != s) {//遍历这条增广路，正向边减流反向边加流
			i = pre[x];
			edge[i].flow -= incf[t];
			edge[i^1].flow += incf[t];
			x = edge[i^1].to;
		}
	}
}
int main() 
{
	scanf("%d%d%d%d", &n,&m,&s,&t);
	while(m--)
    {
        int u, v, w, x;
		scanf("%d%d%d%d",&u,&v,&w,&x);
		addE(u,v,w,x);
		addE(v,u,0,-x);//反向边费用为-f[i]
	}
	MCMF();//最小费用最大流
	printf("%d %d\n",maxflow,mincost);
	return 0;
}