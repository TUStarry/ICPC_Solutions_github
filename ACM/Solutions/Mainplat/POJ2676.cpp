#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int mp[10][10];
bool col[10][10];
bool grid[10][10];
bool row[10][10];
int startxy[4][4];
bool dfs(int x, int y)
{
    if(x == 10) return true;
    int flag = 0;
    if(mp[x][y])
    {
        if(y == 9) flag = dfs(x+1,1);
        else flag = dfs(x, y+1);
        if(flag) return true;
        else return false;
    }
    else
    {
        int k=3*((x-1)/3)+(y-1)/3+1;
        for(int i=1; i<=9; i++)
            if(!row[x][i] && !col[y][i] && !grid[k][i])
            {
                mp[x][y] = i;
                row[x][i] = true;
                col[y][i] = true;
                grid[k][i] = true;
                if(y == 9) flag = dfs(x+1,1);
                else flag = dfs(x,y+1);
                if(!flag)
                {
                    mp[x][y] = false;
                    row[x][i] = false;
                    col[y][i] = false;
                    grid[k][i] = false;
                }
                else return true;
            }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        memset(col,false,sizeof(col));
        memset(grid,false,sizeof(grid));
        memset(row,false,sizeof(row));
        memset(startxy,0,sizeof(startxy));
        for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = ch - 48;
            if(mp[i][j])
            {
                int k=3*((i-1)/3)+(j-1)/3+1;
                row[i][mp[i][j]] = true;
                col[j][mp[i][j]] = true;
                grid[k][mp[i][j]] = true;
                startxy[i/3+1][j/3+1]++;
            }            
        }
        // for(int i=1;i<=3;i++)
        // {
        //     for(int j=1;j<=3;j++)
        //         cout<<startxy[i][j]<<" ";
        //     cout<<endl;          
        // }
        dfs(1,1);
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
                cout<<mp[i][j];
            cout<<endl;
        }
    }
    return 0;
}