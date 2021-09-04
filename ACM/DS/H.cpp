#include<iostream>
#include<cstring> 
using namespace std;
const int maxn = 500;
int n;
int array[maxn][maxn];
struct Kru{
    int bef, aft, data, flag;
    Kru(){
        bef = aft = -1;
        data = flag = 0;
    }
};
void prim(string str[], int n, int po){
    int index = po;
    int sum = 0; 
    int vis[maxn];
    int dist[maxn];
    int cur[maxn]; 
    memset(vis, false, sizeof(vis));
    vis[index] = true;
    int bef = index;
    for(int i = 0; i< n ; i++){
        dist[i] = array[index][i];
        cur[i] = index* 100+ i;
    }
    string beff[maxn];
    string aft[maxn];
    int quan[maxn];
    int r = 0;
    for(int i = 1; i< n; i++){
       int minn = 10000;    
        for(int j = 0; j< n; j++){
            if(!vis[j]&&dist[j]< minn){
                minn = dist[j];
                index = j;
            }
         }
         vis[index] = true;
         beff[r] = str[cur[index]/100];
         aft[r] = str[index];
         quan[r++] = dist[index];
         sum += dist[index];
          
         for(int j = 0; j< n; j++){
            if(!vis[j]&&dist[j]> array[index][j]){
                dist[j] = array[index][j];
                cur[j] = index* 100+ j;
            }
        }
    }
     cout<<sum<<endl<<"prim:"<<endl;
     for(int i = 0; i< r; i++){
        cout<<beff[i]<<' '<<aft[i]<<" "<<quan[i]<<endl;
     }
}
int findmin(Kru kr[], int in){
    int minn = 10000;
    int index = 0;
    int flag = 0;
     for(int i = 0; i< in; i++){
        if(!kr[i].flag&&kr[i].data< minn){
            minn = kr[i].data;
            index = i;
            flag = 1;
        }
    }
    return index;
}
int find(string str[], int n, string st){
    for(int i = 0; i< n; i++)
      if(str[i] == st)
        return i;
}
void change(int vis[], int n, int a, int b){
    for(int i = 0; i< n; i++)
        if(vis[i] == a)
            vis[i] = b;
}
void kruskal(string str[], int in, int n, Kru kr[]){
    int vis[maxn];
    for(int i = 0; i< n; i++) vis[i] = i;
    cout<<"kruskal:"<<endl;
    int k = 0;
    while(true){
        int minn = findmin(kr, in);
        kr[minn].flag = 1;
        int t1 = kr[minn].bef;
        int t2 = kr[minn].aft;
        if(vis[t1] != vis[t2]){
            if(t1> t2){
               int t = t1;
               t1 = t2;
               t2 = t;
            }
           cout<<str[t1]<<" "<<str[t2]<<" "<<kr[minn].data<<endl;
           change(vis, n, vis[t1], vis[t2]);
        }
        k++;
        if(k >= in) break;
    }
}
int main()
{
    while(cin>>n)
    {
        string str[100];
        for(int i = 0; i< n; i++) cin>>str[i];
        for(int i = 0; i< n; i++)
            for(int j = 0; j< n; j++)
                array[i][j] = 10000;  
        int in;
        cin>>in;      
        Kru kr[maxn];
            for(int j = 0; j< in; j++)
            {
                string s1, s2;
                int shu;
                cin>>s1>>s2>>shu;
                int t1 = find(str, n, s1);
                int t2 = find(str, n, s2);
                array[t1][t2] = shu;
                array[t2][t1] = shu;
                kr[j].bef = t1;
                kr[j].aft = t2;
                kr[j].data = shu;
                kr[j].flag = 0;
            }
        string s;
        cin>>s;
        int d = find(str, n, s);
        prim(str, n, d) ; 
        kruskal(str, in, n, kr);
    }
    return 0;
}
