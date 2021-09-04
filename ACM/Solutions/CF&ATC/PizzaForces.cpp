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
const int maxn = 500005;
inline ll read()
{
    ll num = 0, fu = 1;
    char ch = getchar();
    while('0'>ch||ch>'9') {if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return num*fu;
}
//6 8 10
//15 20 25
ll a[4] = {0,6,8,10};
ll b[4] = {0,15,20,25};
int main()
{
    ll t = read();
    while(t--)
    {
        ll num = read();
        ll ans = 1e18;
        if(num % 6 == 0)
            ans = min(ans, num / 6 * 15 );  
        else if (num % 8 == 0)
            ans = min(ans,  num / 8 * 20);
        else if(num % 10 == 0)
            ans = min(ans, num / 10 * 25);
        else if ( num >= 10)
        {
            if(num % 2 == 1 ) ans =  (num+1) * 5 / 2 ;
            else ans = num * 5 / 2;
        }
        else{
             for(int i=1;i<=3;i++)
                ans = min(ans, (num / a[i] + 1) * (b[i]) );
        }
        cout<<ans<<endl;
    }

    return 0;
}