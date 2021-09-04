#include<iostream>
const int maxn = 500;
using namespace std;
struct Node{
    int id;
    char data;
    Node* nxt;
    Node(int in, char ch)
    {
        id = in;
        data = ch;
        nxt = NULL;
    }
};
int find(Node* ma2[], int n, char ch){
    for(int i= 0; i< n; i++)
      if(ma2[i]->data== ch)
        return i;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int cur1= 0;
        Node* ma1[maxn];
        Node* ma2[maxn];
        for(int i= 0; i< n; i++){
            char ch;
            cin >> ch;
            ma1[i]= new Node(i, ch);
            ma2[i]= ma1[i];
        }
        for(int i= 0; i< k; i++){
            char a, b;
            cin >> a >> b;
            int cur1 = find(ma1, n, a);
            int cur2 = find(ma1, n, b);
            ma2[cur1]->nxt= new Node(cur2, b);
            ma2[cur1]= ma2[cur1]->nxt;
        }
        for(int i= 0;  i< n; i++){
            cout<<i<<' '<<ma1[i]->data<<'-';
            Node* p= ma1[i]->nxt;
            while(p){
                cout<<p->id<<'-';
                p= p->nxt;
            }
            cout<<'^'<<endl;
        }
    }   
    return 0;
}