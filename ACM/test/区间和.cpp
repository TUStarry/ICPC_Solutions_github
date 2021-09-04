#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
struct Node
{
    int l, r;
    int val, lazy;
} tr[maxn << 2];
int arr[maxn];
void push_up(int p)
{
    tr[p].val = tr[lson].val + tr[rson].val;
}
void Build(int p, int l, int r)
{
    tr[p].l = l, tr[p].r = r;
    if (l == r)
    {
        tr[p].val = arr[l];
        tr[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    push_up(p);
}
int ask(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r)
        return tr[p].val;
    int mid = (tr[p].l + tr[p].r) >> 1;
    int val = 0;
    if (l <= mid)
        val += ask(lson, l, r);
    if (mid < r)
        val += ask(rson, l, r);
    return val;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    Build(1, 1, n);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", ask(1, l, r));
    }
    return 0;
}