#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 0;
int n;
string s;
void dfs(int cur)
{
    for(int i=cur;i>1;i--)
        if(s[i-1] == '?' && s[i] == 'B') s[i-1] = 'R';
        else if (s[i-1] == '?' && s[i] == 'R') s[i-1] = 'B';
        else break;
    for(int i=cur;i<n;i++)
        if(s[i+1] == '?' && s[i] == 'B') s[i+1] = 'R';
        else if (s[i+1] == '?' && s[i] == 'R') s[i+1] = 'B';
        else break;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(int i=0;i<n;i++)
            if(s[i] != '?')
                dfs(i);
        cout<<s<<endl;
    }
    return 0;
}