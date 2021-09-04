#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 20;
int s[1<<maxn];
int main()
{
    int n;
    cin>>n;
    while(n--){
       int D,I;
        while(~scanf("%d %d",&D,&I)){
           memset(s,0,sizeof(s));
        int k, n = (1<<D)-1;
        for(int i=1;i<=I;i++){
            k=1;
            for(;;){
                s[k] = !s[k];
                k = s[k] ? k*2 : k*2+1;
                if(k>n) break;
            }
        }
        cout<<k/2<<endl;
        }
    }

    return 0;
}
 /* Ä£Äâ²¿·Ö
 memset(s,0,sizeof(s));
        int k, n = (1<<D)-1;
        for(int i=1;i<=I;i++){
            k=1;
            for(;;){
                s[k] = !s[k];
                k = s[k] ? k*2 : k*2+1;
                if(k>n) break;
            }
        }
        cout<<k/2<<endl;
*/
/**/
