#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
#define MAXN 105
using namespace std;

inline int read(){
    int num = 0, fu = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return fu*num;
}
int n, m, cnt, idx[MAXN][MAXN];
char pic[MAXN][MAXN];
void dfs(int r, int c, int id){
    if(r<=0 || r>m || c<=0 || c>n) return ;
    if(idx[r][c] != 0 || pic[r][c] != '@') return ;
    idx[r][c] = id;
    for(int i=-1; i<=1; i++)
    for(int j=-1; j<=1; j++){
        if(i != 0 || j != 0)
            dfs(r+i, c+j, id);
    }

}

int main()
{
    while(scanf("%d%d", &m, &n) == 2 && n && m){
        memset(idx, 0, sizeof(idx));
        cnt = 0;
        for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>pic[i][j];
        for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(idx[i][j] == 0 && pic[i][j] == '@'){
                dfs(i, j, ++cnt);
            }
        }
    printf("%d\n",cnt);
    }
    return 0;
}
