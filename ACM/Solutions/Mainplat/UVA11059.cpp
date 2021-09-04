#include<iostream>
#include<cstdio>
using namespace std;
long long int s[20];
int main(){
   int n,CASE=0;
   while(cin>>n){
   	long long ans=0;
   	for (int i=0;i<n;++i)	cin>>s[i];
   	for (int i=1;i<=n;++i){
   		for (int j=0;j+i<=n;++j){
   			long long jilu=1;
   			for (int k=j;k<j+i;++k)
   				jilu*=s[k];
   			ans=max(ans,jilu);
   		}
   	}
   	printf("Case #%d: The maximum product is %lld.\n\n",++CASE,ans);
   }
   return 0;
}
