//Disjoint Set Union
//并查集
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e6;
int fa[maxn];
int rnk[maxn];
inline void init(int n){
    for(int i=1;i<=n;i++){
        fa[i] = i;
        rnk[i] = 1;
    }
}
int find(int x){
    return x == fa[x] ? x :(fa[x] = find(fa[x]));
}
inline void merge(int i, int j){
    int x = find(i), y = find(j); //先找到两个根节点
    if(rnk[x] <= rnk[y]) fa[x] = y;
    else fa[y] = x;
    if (rnk[x] == rnk[y] && x != y) rnk[y]++;   //如果深度相同且根节点不同，则新的根节点的深度+1
}
int main()
{

    return 0;
}