#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 0;
int money[7] = {100, 50, 20, 10, 5, 2, 1};
int ans[7];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 7; i++)
        {
            ans[i] = n / money[i];
            n %= money[i];
        }
        int tot = 0, totm = 0, flag = 1;
        for (int i = 0; i < 7; i++)
            if (ans[i] != 0)
            {
                tot += ans[i];
                totm += ans[i] * money[i];
            }
        printf("%d ", tot);
        for (int i = 0; i < 7; i++)
        {
            if(ans[i] != 0)
            {
                if(!flag)
                    printf("+");
                if(ans[i] == 1)
                    printf("%d", money[i]);
                else
                    printf("%d*%d",money[i],ans[i]);
                flag = 0;
            }
        }
        printf("=%d\n",totm);
    }
    return 0;
}