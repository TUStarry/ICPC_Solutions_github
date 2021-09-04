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
    freopen("01.in", "w", stdout);
}
int main()
{
    gen();
    srand(time(NULL));
    int t = rand1(50);
    while (t--)
    {
        char ch;
        int len1 = rand1(1000, 10);
        int len2 = len1 - 1;
        for (int i = 1; i <= len1; i++)
            printf("%c", ch = rand1(123, 97));
        printf(" ");
        for (int i = 1; i <= len2; i++)
            printf("%c", ch = rand1(123, 97));
        print();
    }
    return 0;
}
