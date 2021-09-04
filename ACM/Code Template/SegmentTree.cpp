#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
typedef long long ll;
const int maxn = 3e5+5;
struct Node{
    int l, r;
    int val, lazy;
}tr[maxn<<2];
int arr[maxn];
void push_up(int p){//建树与题目相关
    tr[p].val = tr[lson].val + tr[rson].val;
}
void push_down(int p){//下放懒标记
    if(tr[p].lazy){
        tr[lson].val += tr[p].lazy * (tr[lson].r - tr[lson].r + 1);//
        tr[rson].val += tr[p].lazy * (tr[rson].r - tr[rson].r + 1);//
        tr[lson].lazy += tr[p].lazy;
        tr[rson].lazy += tr[p].lazy;
        tr[p].lazy = 0;
    }
}
void Build(int p, int l, int r){//建树
    tr[p].l = l, tr[p].r = r;
    if(l == r){
        tr[p].val = arr[l];
        tr[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    push_up(p);
}
int ask(int p, int l, int r){//区间查询
    if(l <= tr[p].l && tr[p].r <= r) return tr[p].val;
    push_down(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    int val = 0;
    if(l <= mid) val += ask(lson, l, r);
    if(mid< r) val += ask(rson, l, r);
    return val; 
}
void modify(int p, int l, int r, int val){//区间修改
    if(tr[p].l == l && tr[p].r == r){
        tr[p].lazy = val;
        tr[p].val = val * ( r - l + 1);
        return;
    }
    push_down(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(r <= mid) modify(lson, l, r, val);
    else if(mid < l) modify(rson, l, r, val);
    else{
        modify(lson, l, mid, val);
        modify(rson, mid + 1, r, val);
    }
    push_up(p);
}
int main()
{
    int h, w, n;
    while(scanf("%d%d%d", &h, &w, &n) != EOF)
    {

    }
    return 0;
}