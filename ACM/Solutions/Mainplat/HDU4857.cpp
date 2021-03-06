#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 30001
using namespace std;
int n, m;
vector<int> G[MAXN];
vector<int> topo;
int in[MAXN];

bool toposort()
{
    priority_queue<int> que;
    for(int i=1;i<=n;i++)
        if(in[i]==0)
			que.push(i);
    while(!que.empty()){
        int u = que.top();
        que.pop();
        topo.push_back(u);
        for(int i=0;i<G[u].size();i++){
            int vv=G[u][i];
            if(--in[vv] == 0)
				que.push(vv);
        }
    }
    if(topo.size() != n)
		return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    	memset(in,0,sizeof(in));
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<=n;i++)
            G[i].clear();
        topo.clear();
        
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[b].push_back(a);
            in[a]++;
        }
        if(toposort()){
            for(int i=n-1;i>=0;i--){
                if(i != n-1)
					printf(" ");
                printf("%d",topo[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
