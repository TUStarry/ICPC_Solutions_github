#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
#define maxn 35
double mp[maxn][maxn];
bool Floyd(int n)
{
	for(int k = 0;k<n;k++)
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				if(mp[i][j]<mp[i][k]*mp[k][j])  
				    mp[i][j] = mp[i][k]*mp[k][j];
	for(int i = 0;i<n;i++)
		if(mp[i][i]>1.0)
		    return true;
	return false;
}
int main()
{
	int n, m;
	string na, nb, name;
	double rate;
    int T;
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n >> m;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    mp[i][j] = 0;
            map<string, int>ma;
            for(int i=0;i<n;i++)
            {
                cin >> name;
                ma[name] = i;
            }
            for(int i=0;i<m;i++)
            {
                cin >> na >> rate >> nb;
                mp[ma[na]][ma[nb]] = rate;
                mp[i][i] = 1;
            }
            if(Floyd(n)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }        
    }

    return 0;
}