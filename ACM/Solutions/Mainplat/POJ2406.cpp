#include<cstdio>
#include<cstring>
#include<iostream>
const int maxn = 1000001;
int list1[maxn];
char arr[maxn];
void kmp(char *s) {
    list1[0] = -1;
    int len = strlen(s);
    int cur = 0, k = -1;
    while(cur < len) {
        if(k == -1 || s[cur] == s[k])
            list1[++cur] = ++k;
        else
            k = list1[k];
    }
}
int main() {
    while(gets(arr)) {
        if(strcmp(arr,".") == 0) {
            return 0;
        }
        kmp(arr);
        int ans = 1;
        int l = strlen(arr);
        if(l % (l - list1[l]) == 0) {
                std::cout<<l - list1[l]<<std::endl;
            ans = l / (l - list1[l]);
        }
        printf("%d\n", ans);
    }
}
