#include<iostream>
#include<cstdio>
#include<cstring>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
inline int read()
{
    int fu = 1, num = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num*10)+(ch-'0');ch=getchar();}
    return num*fu;
}
const int maxn = 1e5+10;
struct Segmenttree{
    int l, r;
    ll val, lazy;
}t[maxn*4];
int a[maxn];
void Build(int p, int l, int r){
    t[p].r = r; 
    t[p].l = l;
    if(l == r){
        t[p].val = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    if(l<=mid)Build(ls, l, mid);
    if(r> mid) Build(rs, mid+1, r);
    t[p].val = t[ls].val + t[rs].val;
}
void lazytag(int p){
	if(t[p].lazy){
		t[ls].val += t[p].lazy * (t[ls].r - t[ls].l + 1);
		t[rs].val += t[p].lazy * (t[rs].r - t[rs].l + 1);
		t[ls].lazy += t[p].lazy;
		t[rs].lazy += t[p].lazy;
		t[p].lazy = 0;
	}
}
void change(int p, int x, int y, int val){//区间修改
	if (x <= t[p].l && t[p].r <= y){
		t[p].val += (ll)val * (t[p].r-t[p].l+1);
        t[p].lazy += val;//打上懒标记
        return;
	}
	lazytag(p);
	int mid = (t[p].l + t[p].r) / 2; //熟悉的二分 
	if (x <= mid) change(ls, x, y, val); 	//x在左边 
	if (mid < y) change(rs, x, y, val); //x在右边 
	t[p].val = t[ls].val + t[rs].val;//看情况
} 
ll query(int p,int x, int y){//区间查询
	if(x <= t[p].l && t[p].r <= y) return t[p].val;
    lazytag(p);
	int mid = (t[p].l + t[p].r) >> 1;ll val = 0;
	if (x <= mid) val += query(ls, x, y);
	if (mid < y) val += query(rs, x, y);	
	return val;
}
int main()
{
    int n, q, x, y, z;
    char ch;
    n = read(), q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    Build(1,1,n);
    while(q--)
    {
        scanf("%c", &ch);
        if(ch == 'Q')
        {
            x = read(), y = read();
            printf("%lld\n", query(1,x,y));
        }
        else if(ch == 'C')
        {
            x = read(), y = read(), z = read();
            change(1,x,y,z);
        }
    }
    return 0;
}