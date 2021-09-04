#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 310001
using namespace std;
typedef long long ll;

struct SplayTree{
    int root;
    int fa[N];
    int ch[N][2];
    int sz[N];
    int top1;
    int top2;
    int ss[N];
    int que[N];

    void rotate(int x,bool f){
        int y=fa[x];
        int z=fa[y];
        pushdown(y);
        pushdown(x);
        ch[y][!f]=ch[x][f];
        fa[ch[x][f]]=y;
        fa[x]=z;
        if (z) {
            ch[z][ch[z][1]==y] = x;
        }
        ch[x][f] = y;
        fa[y]=x;
        pushup(y);
    }
    void splay(int x, int g) {
        int y = fa[x];
        pushdown(x);
        while(y!=g){
            int z= fa[y];
            bool f = (ch[y][0]==x);
            if(z != g && f == (ch[z][0]==y)){
                rotate(y,f);
            }
            rotate(x,f);
            y=fa[x];
        }
        pushup(x);
        if(g==0) root = x;
    }
    void rotateTo(int k,int g) {
        int x=root;
        pushdown(x);
        while(sz[ch[x][0]] != k){
            if(k<sz[ch[x][0]]){
                x=ch[x][0];
            }else{
                k -= sz[ch[x][0]] + 1;
                x = ch[x][1];
            }
            pushdown(x);
        }
        splay(x,g);
    }
    void build(int l,int r,int f){
        if(l>r){
            return ;
        }
        int x = (l + r) >> 1;
        ch[x][0] = (x - 1 >= l)? (x - 1 + l)>> 1 :0;
        ch[x][1] = (r >= x + 1)? (x + 1 + r)>> 1 :0;
        fa[x] = f;
        build(l,x - 1,x);
        build(x + 1,r,x);
        pushup(x);
    }
    void erase(int x){
        if(x==0)
            return;
        int father= fa[x];
        int head = 0, tail=0;
        for(que[tail++] =x ; head < tail; head++){
            ss[top2++] = que[head];
            if(ch[que[head]][0]){
                que[tail++]=ch[que[head]][0];
            }
            if(ch[que[head]][1]){
                que[tail++] = ch[que[head]][1];
            }
        }
        ch[father][ch[father][1]==x]=0;
        pushup(father);
    }
    void makeTree(int &x, int l, int r, int f){
        if(l > r){
            return;
        }
        int m=(l+r)>>1;
        newNode(x, num[m]);
        makeTree(ch[x][0],l,m-1,x);
        makeTree(ch[x][1],m+1,r,x);
        fa[x]=f;
        pushup(x);
    }


    void newNode(int &x,int c){
        if(top2){
            x = ss[--top2];
        } else {
            x = ++top1;
        }
        ch[x][0] = ch[x][1] = fa[x] =0;
        sz[x] = 1;
        val[x]=c;
        flip[x]=add[x]=0;

    }
    void pushdown(int x){
        if(add[x]){
            add[ch[x][0]]+=add[x];add[ch[x][1]]+=add[x];
            val[ch[x][0]]+=add[x];val[ch[x][1]]+=add[x];
            add[x]=0;
        }
        if(flip[x]){
            flip[ch[x][0]]^=1;flip[ch[x][1]]^=1;
            reverse(ch[x][0]);reverse(ch[x][1]);
            flip[x]=0;
        }
    }
    void pushup(int x){
        sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];
    }
    void reverse(int x){
        swap(ch[x][0],ch[x][1]);
    }
    void treaval(int x){
        if (x) {
            pushdown(x);
            treaval(ch[x][0]);
            printf("@%I64d",val[x]);
            treaval(ch[x][1]);
        }
    }
    void debug(){
        treaval(root);
        cout<<endl;
    }
    void cutTo(int l,int r,int c){
        rotateTo(l-1,0);
        rotateTo(r+1,root);
        int tmp=ch[ch[root][1]][0];
        ch[ch[root][1]][0]=0;
        pushup(ch[root][1]);
        pushup(root);

        rotateTo(c,0);
        rotateTo(c+1,root);
        fa[tmp]=ch[root][1];
        ch[ch[root][1]][0]=tmp;
        pushup(ch[root][1]);
        pushup(root);
    }
    void gettar(int len){
        int size=sz[root]-2;
        if(pot+len-1>size){
            cutTo(pot,size,0);
            pot=1;
        }
        rotateTo(pot-1,0);
        rotateTo(pot+len,root);
    }
    void Add(int x){
        gettar(k2);
        add[ch[ch[root][1]][0]]+=x;
        val[ch[ch[root][1]][0]]+=x;
    }
    void Rever(){
        gettar(k1);
        flip[ch[ch[root][1]][0]]^=1;
        reverse(ch[ch[root][1]][0]);
    }
    void Insert(int x){
        rotateTo(pot,0);
        rotateTo(pot+1,root);
        newNode(ch[ch[root][1]][0],x);
        fa[ch[ch[root][1]][0]]=ch[root][1];
        pushup(ch[root][1]);
        pushup(root);
    }
    void Dele(){
        rotateTo(pot-1,0);
        rotateTo(pot+1,root);
        erase(ch[ch[root][1]][0]);
        pushup(ch[root][1]);
        pushup(root);

        int size=sz[root]-2;

        if(pot>size)pot=1;
    }
    void Move(int x){
        int size=sz[root]-2;
        if(x==1){
            pot--;
            if(pot==0){
                pot=size;
            }
        }else{
            pot++;
            if(pot>size){
                pot=1;
            }
        }
    }
    void Query(){
        rotateTo(pot,0);
        printf("%I64d\n",val[root]);
    }
    void init(int n,int K1,int K2){
        k1=K1,k2=K2;
        top1=top2=root=0;
        newNode(root,0);
        newNode(ch[root][1],0);
        fa[ch[root][1]]=root;
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        makeTree(ch[ch[root][1]][0],1,n,ch[root][1]);
        pot=1;
        pushup(ch[root][1]);
        pushup(root);
    }
    void solve(int m){
        char op[10];
        int x;
        //debug();
        for(int i=1;i<=m;i++){
            //cout<<sz[root]<<endl;
            scanf("%s",op);
            if(op[0]=='q'){
                Query();
            }else if(op[0]=='m'){
                scanf("%d",&x);
                Move(x);
            }else if(op[0]=='i'){
                scanf("%d",&x);
                Insert(x);
            }else if(op[0]=='r'){
                Rever();
            }else if(op[0]=='a'){
                scanf("%d",&x);
                Add(x);
            }else{
                Dele();
            }
            //debug();
        }
    }
    int pot;
    int k1,k2;
    ll val[N];
    int flip[N];
    ll add[N];
    int num[N];

}spt;
int main()
{  
    int n,m,k1,k2;
    int cas=1;
    while(scanf("%d%d%d%d",&n,&m,&k1,&k2),n||m||k1||k2)
    {
        printf("Case #%d:\n",cas++);
        spt.init(n,k1,k2);
        spt.solve(m);

    }
    return 0;
}