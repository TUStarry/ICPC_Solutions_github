#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1000000+1,MOD=1e9+7;
vector<int>G[maxn];
int dep[maxn];
bool vis[maxn];
int cnt[maxn];
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    if(N == 1 && M == 0) printf("0");//这个需要特判
    else
    {
        for(int i=1;i<=M;i++)
        {
            int x, y;
            scanf("%d%d" ,&x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        queue<int>Q;
        dep[1] = 0;
        vis[1] = 1;
        Q.push(1);
        cnt[1] = 1;
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for(int i=0; i<G[x].size(); i++)
            {
                int t = G[x][i];
                if(!vis[t])
                {
                    vis[t] = 1;
                    dep[t] = dep[x] + 1;
                    Q.push(t);
                }
                if(dep[t]==dep[x]+1)
                    cnt[t] = (cnt[t] + cnt[x]) % MOD;
                    
            }
        }
        printf("%d\n",cnt[N]);

    }
    return 0;
}