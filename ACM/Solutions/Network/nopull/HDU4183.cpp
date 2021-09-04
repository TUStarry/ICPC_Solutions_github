// Difficulty: 2
// Title: Pahom on Water
// Score: HDU - 4183 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 500005;
inline int read()
{
    int num = 0, fu = 1;
    char ch = getchar();
    while('0'>ch||ch>'9') {if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return num*fu;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, x, y, r;
        double hz;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%d%d%d",&hz, &x, &y, &r);
        }
    }
    return 0;
}