#include "stdio.h"
int c = 0;
void mo(int n, char a, char b)
{
    printf("Move disk %d from %c to %c\n",  n, a, b);
}
void han(int n, char a, char b, char c)
{
    if (n == 1)
        mo(n, a, c);
    else
    {
        han(n - 1, a, c, b);
        mo(n, a, c);
        han(n - 1, b, a, c);
    }
}
int main()
{
    int n, num;
    while (scanf("%d", &n) != EOF)
    {
        han(n, 'A', 'B', 'C');
        printf("\n");
    }
    return 0;
}
