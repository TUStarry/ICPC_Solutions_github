#include<iostream>
#include<queue>
using namespace std;
int n,m;
int nx[4] = {0,0,1,-1};
int ny[4] = {1,-1,0,0};
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int M[40][40]={0};
        queue<int>x;
        queue<int>y;
        int num=0;
        cin >>  n >> m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin >> M[i][j];
        x.push(0);
        y.push(0);
        while(!x.empty())
        {
            for(int i=0;i<4;i++)
                if(x.front()+nx[i]<=n&&x.front()+nx[i]>=0&&y.front()+ny[i]<=m&&y.front()+ny[i]>=0&&M[x.front()+nx[i]][y.front()+ny[i]]==0)
                {
                    x.push(x.front()+nx[i]);
                    y.push(y.front()+ny[i]);
                    M[x.front()+nx[i]][y.front()+ny[i]] = 1;
                }
            x.pop();
            y.pop();
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(M[i][j]==0)
                    num++;
        cout<<num<<endl;
    }
    return 0;
}