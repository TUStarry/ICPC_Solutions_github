#include <iostream>
using namespace std;
#define inf 65535
const int maxn = 250;
int array[maxn][maxn], n;
void dij(int v)
{
    int D[n];
    bool final[n];
    int pathLen[n];
    int path[250][250];
    int start = v;
    for(int i=0;i<n;i++)
    {
        D[i] = array[v][i];
        final[i] = false;
        pathLen[i] = 2;     
    }
    for(int i =0;i<n;i++)
    {
        path[i][0] = v;
        path[i][1] = i;
    }
    final[v] = true;
    D[v] = 0;
    for(int i=0;i<n;i++)   
    {
        int min=inf;
        for(int j=0;j<n;j++)
        {
            if(!final[j] && D[j]<min)
            {
                min = D[j];
                v = j;
            }
        }

        if(min == inf) break;
        final[v] = true;
        for(int j=0;j<n;j++)  
        {
            if(!final[j] && array[v][j]+min < D[j]){
                D[j] = array[v][j] + min;
                for(int k=0;k<pathLen[v];k++)
                    path[j][k] = path[v][k];

                pathLen[j] = pathLen[v]+1;
                path[j][pathLen[j]-1] = j;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==start) continue;
        cout<<start<<'-'<<i<<'-'<<D[i]<<"----[";
        for(int j=0;j<pathLen[i];j++)
            cout<<path[i][j]<<' ';
        cout<<']'<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int num;
            cin >> num;
            if(num == 0) array[i][j] = inf;
            else array[i][j] = num;
        }
             
        int v;        
        cin>>v;
        dij(v);
    }
    return 0;
}