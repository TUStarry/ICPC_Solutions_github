#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#define error -1
#define ok 1
using namespace std;
typedef long long ll;
const int maxn = 1e6;
inline ll read()
{
    ll num = 0, fu = 1;
    char ch = getchar();
    while('0'>ch||ch>'9') {if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return num*fu;
}
ll num[maxn];
ll maxx[maxn];
ll minn[maxn];
int  main()
{
    ll t = read();
    while(t--)
    {
        ll n = read(), m = read();
        ll maxnum = -1, minnum = 1e10;
        ll ans = 0;
        for(int i=1;i<=n;i++)
            num[i] =read();
        for(int i=1;i<n;i++)
            ans = max(num[i]*num[i+1], ans);
        cout<< ans <<endl;
            
    }
    return 0;
}