#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
int rand1(int mod, int low = 0)
{
    if (low != 0)
        return rand() * rand() % (mod - low) + low;
    else
        return rand() * rand() % mod + low;
}
void print(int n = 0, int flag = 3)
{
    if (flag == 1)
        printf("%d\n", n);
    if (flag == 2)
        printf("%d ", n);
    if (flag == 3)
        printf("\n");
}
void gen()
{ //数字手动输入， 人工智障//97 - 122
    freopen("06.in", "w", stdout);
}
int main()
{
    gen();
    srand(time(NULL));
    int t = 1;
    while (t--)
    {
        int n = rand1(200, 10);
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            int num = rand1(50, 1);
            print(num, 2);
        }
        cout << endl;
    }
    return 0;
}
