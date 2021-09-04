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
    int t = read();
    while(t--)
    {
        int n = read(), m = read();
        int ans = 0;
        for(int i=0;i<=m;i++)
        {
            if(i ^ n > 0) ans++;
            cout << "/" << (i ^ n) << endl;

        }
            
        cout<<ans<<endl;
    }
    return 0;
}