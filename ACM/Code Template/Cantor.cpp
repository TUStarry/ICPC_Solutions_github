#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 500005;
ll fac[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800}; //0-10的阶乘 
ll cantor(int p[],int n)
{
    ll ans = 1;
    for(int i=0;i<n;i++)
    {
        ll cnt = 0;
        for(int j=i+1;j<=n;j++)
            if(p[i] > p[j]) cnt++;
        ans += cnt * fac[n-i-1];
    }
    return ans;
}
vector<int> decantor(int x, int n)
{
    vector<int> v;  
    vector<int> a;
    for(int i=1;i<=n;i++) v.push_back(i);
    for(int i=n;i>=1;i--)
    {
        int r = x % fac[i-1];
        int t = x / fac[i-1];
        x = r;
        sort(v.begin(),v.end());
        a.push_back(v[t]);
        v.erase(v.begin()+t);
    }
    return a;
}
int main()
{
    int a[9]={1,2,3,4,5,6,7,8,0};
    
    cout<<cantor(a,9)<<endl;
    return 0;
}