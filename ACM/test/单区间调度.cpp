#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
struct Node
{
    int st, ed;
} tr[maxn];
bool cmp(Node a, Node b)
{
    if (a.ed != b.ed) return a.ed < b.ed;
    else return a.st > b.st;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &tr[i].st, &tr[i].ed);
        sort(tr + 1, tr + 1 + n, cmp);
        int ans = 1;
        int temp = tr[1].ed;
        for (int i=2;i<=n;i++)
        {
            if(tr[i].st >= temp)
            {
                ans ++ ;
                temp = tr[i].ed;
            }
        }
        cout << ans << endl;
    }
    return 0;
}