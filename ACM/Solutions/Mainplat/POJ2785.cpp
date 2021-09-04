#include<cstdio>
#include<cstring> 
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long int
const int maxn = 4040;
int A[maxn], b[maxn], c[maxn], d[maxn], list1[maxn*maxn], list2[maxn*maxn], len = 0;

int bs(int x){
    int l=0, r=len-1, mid=0;
    while(l <= r) {
        mid=(l + r) / 2;
        if(x == list2[mid]) {
            int cur = mid, w = 0;
            while(x == list2[cur] && cur < len){
                cur++,w++;
            }
            cur = mid - 1;
            while(x == list2[cur] && cur >= 0){
                cur--,w++;
            }
            return w;
        }
        else if(x < list2[mid]){
            r = mid - 1;
        }
        else if(x > list2[mid]){
            l = mid + 1;
        } 
    }
    return 0;
}

int main()
{    
    int n, total = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&A[i],&b[i],&c[i],&d[i]);
    }
    len=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        list1[len]=A[i]+b[j];
        list2[len++]=-(c[i]+d[j]);
    }
    std::sort(list2,list2+len);
    for(int i=0;i<len;i++){
        int ans = bs(list1[i]);
        total += ans;
    }
    printf("%d\n", total);

} 
