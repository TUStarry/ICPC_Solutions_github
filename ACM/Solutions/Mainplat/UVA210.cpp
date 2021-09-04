#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;

inline int read(){
	int num=0,fu=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<1)+(num<<3)+(ch^48);ch=getchar();}
	return num*fu;
}
int n,t[6],Q;

int main()
{
	n=read();
	for(int i=1;i<=5;i++) t[i]=read();
	Q=read();
	while(n--){
		
	}
	cout<<n; 	
}

