#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[17]={0,1},n;
bool vis[17]={0,1};
bool isp[40]={0};
void dfs(int cur){
    if(cur == n+1 && isp[A[1]+A[n]] ){
        for(int i=1;i<n;i++) printf("%d ",A[i]);printf("%d",A[n]);
        printf("\n");
    }
    else for(int i=2;i<=n;i++){
        if(!vis[i] && isp[i + A[cur-1]]){
            A[cur] = i;
            vis[i] = 1;
            dfs(cur+1);
            vis[i] = 0;
        }
    }
}
int main()
{
    int flag=0;
    isp[2]=isp[3]=isp[5]=isp[7]=isp[11]=isp[13]=isp[17]=isp[19]=isp[23]=isp[29]=isp[31]=1;// 素数
    while(scanf("%d",&n)!=EOF){
        if(flag++) {printf("\n");}
        printf("Case %d:\n",flag);
        dfs(2);
    }
    return 0;
}
