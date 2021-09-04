#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 30001
using namespace std;

struct jewels {
	int vi;
	int wi;
	double si;
	int num;
    bool operator <(const jewels &n)const {
        return si>n.si;
    }
};

jewels j[100001];
int total[100001];
bool check(int n, int k, double mid){
	for (int i=1;i<=n;i++)
		j[i].si = j[i].vi - j[i].wi * mid;
	sort(j+1, j+n+1);
	double sum = 0;
	for (int i=1;i<=k;i++)	{
		sum += j[i].si;
		total[i] = j[i].num;
	}
	return sum > 0;
} 
int main(){
	int n, k;
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&j[i].vi, &j[i].wi);
			j[i].num = i;
		}
		double l = 0, r = 1e10;
		while(r-l > 1e-8){
			double mid = (l + r) / 2;
			if (check(n, k, mid))
				l = mid;
			else
				r = mid;
		}
		for(int i=1;i<=k;i++)
			printf("%d ", total[i]);
		printf("\n");
		
	}
	return 0;
}
