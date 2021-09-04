#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
struct Node
{
    int st, ed;
} a[maxn];
bool cmp(Node a, Node b)
{
    return a.st < b.st;
}
multiset<int> st;
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        st.clear();
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].st, &a[i].ed);
        sort(a, a + n, cmp);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = st.upper_bound(a[i].st);
            if (it == st.begin())
            {
                ans += a[i].ed - a[i].st;
                st.insert(a[i].ed);
            }
            else
            {
                it--;
                ans += a[i].ed - *it;
                st.erase(it);
                st.insert(a[i].ed);
            }
        }
        cout << st.size() << " " << ans << endl;
    }
    return 0;
}