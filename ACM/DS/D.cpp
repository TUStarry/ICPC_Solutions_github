#include <iostream>
using namespace std;
const int maxn = 250;
int m[maxn][maxn], vis[maxn], n;
void DFS(int temp)
{
    for(int j=0;j<n;j++)
        if(m[temp][j]==1 && vis[j]==0)
        {
            vis[j]=1;
            DFS(j);
        }
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) vis[i] = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            vis[i] = 0;
            DFS(i);        
            for(int j=0; j<n; j++)
            {
                if(vis[j]==0)    
                {
                    flag=1;
                    break;
                }
                else
                    vis[j]=0;
            }
            if(flag==1)
                break;
        }
        if(flag==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}