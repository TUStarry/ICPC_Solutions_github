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
const int maxn = 1e5 + 10;
inline int read()
{
    int num = 0, fu = 1;
    char ch = getchar();
    while('0'>ch||ch>'9') {if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return num*fu;
}
int arr[maxn];
int main()
{
    int t = read();
    while(t--)
    {
        int n = read(), maxnum, cur = 0;
        ll tot = 0;
        for(int i=1;i<=n;i++) {
            arr[i] = read();
            tot += arr[i];
        }
        sort(arr+1,arr+1+n);
        double ans = arr[n] + (double)(tot - arr[n])/(double)(n-1);

        printf("%.09lf\n",ans);
            

    }

    return 0;
}