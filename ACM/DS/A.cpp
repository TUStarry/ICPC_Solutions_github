#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int temp[25][25], n;
bool vis[20];

void dfs(int p){
    vis[p] = true;
    printf("%d ", p);
    for(int i=0;i<=n;i++)
        if(temp[p][i] && !vis[i])
            dfs(i);
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
        for(int i=0;i<n;i++)
            if(!vis[i]) dfs(i);
        printf("\n");
    }
    return 0;
}
