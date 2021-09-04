#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
using namespace std;

inline int read(){

    int num = 0, fu =1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return fu*num;
}
int last, cur, lian[100001];
char s[100001];

int main()
{
    while (scanf("%s",s+1) ==1){
        int n = strlen(s+1);
        last = cur = 0;
        lian[0] = 0;
        memset(lian,0,sizeof(lian));
    for(int i=1;i<=n;i++){
        char ch = s[i];
        if (ch == '[') cur = 0;
        else if(ch ==']') cur = last;
        else{
            lian[i] = lian[cur];
            lian[cur] = i;
            if (cur == last) last = i;
            cur = i ;
        }
        cout<<i<<": ";
        for(int j=0;j<=n;j++) cout<<lian[j]<<" ";
        cout<<endl;
    }
    for(int i = lian[0];i!=0;i =lian[i])
        printf("%c",s[i]);
    printf("\n");
    }
    return 0;
}
//This_is_a_[Beiju]_text
//[[]][][]Happy_Birthday_to_Tsinghua_University
