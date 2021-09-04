#include <iostream>
#include <cstdio>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct Node
{
    int l, r;
    int rest;
} tr[maxn << 2];
int pos[maxn], val[maxn], ans[maxn];
void push_up(int p)
{
    tr[p].rest = tr[lson].rest + tr[rson].rest;
}
void build(int p, int l, int r)
{
    tr[p].l = l;
    tr[p].r = r;
    if (l == r)
    {
        tr[p].rest = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(p);
}
void modify(int p, int pos, int v)
{
    if (tr[p].l == tr[p].r)
    {
        ans[tr[p].l] = v;
        tr[p].rest = 0;
        return;
    }
    if (pos <= tr[lson].rest)
        modify(lson, pos, v);
    else
        modify(rson, pos - tr[lson].rest, v);
    push_up(p);
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &pos[i], &val[i]);
        for (int i = n; i >= 1; i--)
            modify(1, pos[i] + 1, val[i]);
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}