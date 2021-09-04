#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

inline int read(){
    int num = 0, fu =1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return fu*num;
}

struct Matrix{
    int a, b;
    Matrix(int a=0,int b=0) : a(a),b(b){}
}m[26];

stack<Matrix> s;
int main()
{
    int t = read();
    while(t--){//inputÄ£¿é
        char name;
        cin>>name;
        int k = name - 'A';
        cin>>m[k].a >>m[k].b;
    }
    string expr;
    while(cin>>expr){
        int len=expr.length();
        bool error = false;
        int ans = 0 ;
        for(int i=0;i<len;i++){
            if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if (expr[i]==')'){
                Matrix m2 =s.top();s.pop();
                Matrix m1 =s.top();s.pop();
                if(m1.b != m2.a) {error = true;break;}
                ans += m1.a*m1.b*m2.b;
                s.push(Matrix(m1.a,m2.b));
            }
        }
    if(error) cout<<"error"<<endl;
    else cout<<ans<<endl;
    }
    return 0;
}
