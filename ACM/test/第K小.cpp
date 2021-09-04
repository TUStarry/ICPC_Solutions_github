#include <bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int N,M,MM;long long K,A[MAXN];
bool check(long long v)
{
	long long sum=0;
	for (int i=1;i<=N;++i)
		if (A[i]<0)
		{
			int l=i,r=N,mid;
			while (l<r)
			{
				mid=(l+r)>>1;
				if (A[mid+1]*A[i]<=v) r=mid;
				else l=mid+1;
			}
			//printf("%d l=%d %lld\n",A[i],l,A[i]*A[l]);
			sum+=max(N-l,0);
		}
		else if (A[i]==0)
		{
			if (v>=0) sum+=N-i;
		}
		else
		{
			int l=i+1,r=N+1,mid;
			while (l<r)
			{
				mid=(l+r)>>1;
				if (A[mid]*A[i]<=v) l=mid+1;
				else r=mid;
			}
			--l;
			sum+=max(l-i,0);
		}

	return sum>=K;
}
int main()
{
	cin>>N>>K;
	for (int i=1;i<=N;++i) scanf("%lld",&A[i]);
	sort(A+1,A+1+N);
	M=lower_bound(A+1,A+1+N,0LL)-A-1;
	MM=upper_bound(A+1,A+1+N,0LL)-A;
	long long l=-1e18,r=1e18,mid;
	while (l<r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}