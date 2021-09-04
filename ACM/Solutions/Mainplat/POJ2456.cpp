#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long int
int stall[100001], n, c;
bool judge(int k){
	int cur = stall[0], total = 1;
	for(int i=1;i<n;i++)
		if (stall[i] - cur >= k){
			cur = stall[i];
			total++;
		}
	return total >= c;
}
int main(){
	std::cin >> n >> c;
	for(int i=0;i<n;i++)
		scanf("%d",&stall[i]);
	std::sort(stall+0, stall+n);
	int l = 0, r = stall[n - 1]  - stall[0];
	while(l < r){
		int mid = (l + r) / 2;
		//std::cout<<l << " " << r << std::endl;
		if (judge(mid))//can put 
			l = mid + 1;
		else 
			r = mid;
	}
	std::cout<<l-1;
	return 0;
} 
