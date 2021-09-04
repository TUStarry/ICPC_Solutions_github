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
    int a[9] = {0}, m = 4;
    while(m--)
    {
        string s;
        cin >> s;
        if(s == "H") a[1] = 1;
        if(s == "2B") a[2] = 1;
        if(s == "3B") a[3] = 1;
        if(s == "HR") a[4] = 1;
    }
    int ans = 0;
    for(int i=1;i<=4;i++)
        ans += a[i];
    if(ans == 4) printf("Yes");
    else printf("No");
    return 0;
}