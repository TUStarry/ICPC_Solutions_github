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
int s[10];
int check(int a,int b,int c,int d,int e,int n){
    s[a]=s[b]=s[c]=s[d]=s[e]=1;
    int ans=0;
    for(int i=0;i<=9;i++) ans+=s[i];
    if(ans == 5) {
        int total = (a*10000+b*1000+c*100+d*10+e) * n;
        s[total/10000] = s [(total/1000)%10] = s[(total/100)%10] = s[(total/10)%10] = s[total%10] = 1 ;
        ans=0;
        for(int i=0;i<=9;i++) ans+=s[i];
        if(ans == 10) {
            for(int i=0;i<=9;i++) s[i]=0;
            return total;
        }
    }
    for(int i=0;i<=9;i++) s[i]=0;
    return 0;
}

int main()
{
    int N,num=0;
    while(scanf("%d",&N),N){
            if(num++) cout<<endl;
        memset(s,0,sizeof(s));
        int flag = 1;
        for(int a=0;a<=9;a++)
        for(int b=0;b<=9;b++)
        for(int c=0;c<=9;c++)
        for(int d=0;d<=9;d++)
        for(int e=0;e<=9;e++){
           if(check(a,b,c,d,e,N)) {printf("%d / %d%d%d%d%d = %d\n",check(a,b,c,d,e,N),a,b,c,d,e,N);
            flag = 0;
           }
        }
        if(flag) printf("There are no solutions for %d.\n",N);

    }
    return 0;
}
