#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
string s1, s2;
int main()
{
    while(cin >> s1 >> s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        for(int i=0;i<=len1;i++) dp[0][i] = i;
        for(int i=0;i<=len2;i++) dp[i][0] = i;
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
        cout<<dp[len1][len2]<<endl;              
    }
    return 0;
}