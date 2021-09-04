#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

# define MAX 99999
int date[MAX];

int main()
{

	int N,total=0,number,q;
	while(scanf("%d%d",&N,&number)==2&&N)
	{
		cout<<"CASE# "<<++total<<":"<<endl;
		for(int i=0;i<N;i++)
			cin>>date[i];	
		sort(date,date+N);
		while(number--){
			cin>>q;
			int p = lower_bound(date, date+N, q);
			if(date[p] == q) cout<<q<<" found at "<<p+1<<endl;
			else cout<<q<<" not found"<<endl;
		}
	}
	
	
}
