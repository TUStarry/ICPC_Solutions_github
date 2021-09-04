#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int L,n,cnt;
int s[99999];
int dfs(int cur)
{
    if(cnt++ == n){
        int flag = 0,flag_1 = 0;
        for(int i = 0; i < cur; i++){
            if(i % 64 == 0 && ()) printf("\n");
            else if(i % 4 == 0 && (flag++)) printf(" ");
            printf("%c",s[i]+'A');


        }
        printf("\n%d\n",cur);
        return 0;
    }
    else{
        for(int i = 0; i < L; i++){
            s[cur] = i;
            int ok = 1;
            for(int j = 1; j*2 <= cur+1; j++){
                int equal = 1;
                for(int k = 0; k < j; k++)
                    if(s[cur -k] != s[cur -k-j]){
                        equal = 0;
                        break;
                    }
            if(equal == 1){ok = 0;break;}
            }
            if(ok == 1){
                if(!dfs(cur + 1)) return 0;
        }
        }
        return 1;
    }
}
int main()
{
    while(scanf("%d %d", &n, &L) != EOF){
        if(n+L == 0) break;
        cnt = 0;
        memset(s, 0, sizeof(s));
        dfs(0);
    }
    return 0;
}
