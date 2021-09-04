#include<iostream>
using namespace std;
#define maxn 500
int main()
{
    int n;
    while(cin >> n)
    {
        int m[maxn][maxn];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(m[i][j]==0&&m[i][k]==1&&m[k][j]==1)
                        m[i][j]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<m[i][j]<<" ";
            cout<<endl;
        } 
    }
    return 0;
}