#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    int aa= a, bb = b;
    double ans = (a-b) / 3 + b;
    if((aa-bb)%3!=0 ) printf("%.5lf", ans);
    else cout<<ans;
    return 0;
}