#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000;
int arr[maxn];
int main()
{
    int cur = 1;
    for(int i=1;i<=2000;i++)
    {
        int temp = i;
        int flag = 1;
        while(temp){
            int tt = temp %= 10;
            temp /= 10;
            if(tt == 7) flag = 0; 
        }
        if(flag) arr[cur++] = i;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout<< arr[n] <<endl;
    }
    return 0;
}