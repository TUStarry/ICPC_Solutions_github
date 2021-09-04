#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 99
using namespace std;
 
int n;
vector<int> pile[MAXN];
 
int find_block(int a,int &p,int &h){
    for(p=0; p<n; p++)
        for(h=0; h<pile[p].size(); h++)
            if(pile[p][h] == a)   return 0;
}
 
void clear_above(int p,int h){
    for(int i=h+1;i<pile[p].size();i++)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
    return ;
}
 
void pile_onto(int pa,int h,int pb){
    for(int i=h; i<pile[pa].size(); i++)
        pile[pb].push_back(pile[pa][i]);
    pile[pa].resize(h);
    return ;
}

void print(){
    for(int i=0; i<n; i++) {
        cout << i <<":";
        for(int j=0; j<pile[i].size(); j++)
            cout << " " << pile[i][j] ;
        cout << endl;
    }
    return ;
}
 
int main()
{
    string s1,s2;
    int a,b;
    cin >> n ;
        for(int i=0;i<n;i++)   pile[i].push_back(i);
        while(cin>>s1>>a>>s2>>b)
        {
            if(s1 == "quit") break;
            int pa,ha,pb,hb;
            find_block(a,pa,ha);
            find_block(b,pb,hb);
            if(pa == pb) continue;
            if(s2 == "onto")  clear_above(pb,hb);
            if(s1 == "move")  clear_above(pa,ha);
            pile_onto (pa,ha,pb);
        }
       print();
    return 0;
}
