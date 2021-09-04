#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int temp[250][250], n;
bool vis[250];

void bfs(int p){
    vis[p] = true;
    queue<int> q;
    q.push(p);
    while(q.size()){
        int v = q.front();q.pop();
        printf("%d ",v);
        for(int i=0;i<n;i++)
            if(!vis[i] && temp[v][i])
            {
                vis[i] = true;
                q.push(i);
            }
    }

}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(temp, 0, sizeof(temp));
        memset(vis, false, sizeof(vis));
        scanf("%d", &n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d", &temp[i][j]);
        bfs(0);
        printf("\n");
    }
    return 0;
}
