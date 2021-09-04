#include <cstdio>
#include <cstring>
using namespace std;
int n;
char str[100];
int nxt[100];
int len;
void getnxt()
{
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < len){
        if (j == -1 || str[i] == str[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int main()
{
    scanf("%d", &n);
    while (n--){
        scanf("%s", str);
        len = strlen(str);
        getnxt();
        if(len % (len - nxt[len]) == 0)
            printf("%d\n", len - nxt[len]);
        else printf("%d\n", len);
        if(n) printf("\n");
    }
    return 0;
}