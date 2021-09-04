#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod = 99991;
const int maxn = 1000000;
int snow[maxn][6], head[maxn], Next[maxn],tot = 0;
int H(int *a)
{
    int sum = 0, mul = 1;
    for(int i = 0; i< 6; i++){
        sum = (sum + a[i]) % mod;
        mul = (ll)mul * a[i] % mod;
        //printf("sum:%d   mul:%d\n",sum,mul);
    }
    return (sum + mul) % mod;

}
bool equal(int *a, int *b)
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6;j++)
    {
        bool eq = 1;
        for(int k = 0; k < 6;k++)
            if (a[(i+k)%6] != b[(j+k)%6])
                eq = 0;
        if (eq) return 1;
        eq = 1;//����ģ������Ұ��죬������
        for(int k = 0; k< 6; k++){
            /*cout << a[(i+k) % 6] << " " << b[(6+j-k) % 6]<<endl;*/
            if (a[(i+k) % 6] != b[(6+j-k) % 6])
                eq = 0;
        }
            /*cout<<"\n***" <<eq<<endl;*/
        if (eq) return 1;
    }
    return 0;
}
bool insert(int *a)
{
    int val = H(a);
    //printf("%d\n",val);
    for(int i = head[val];i;i = Next[i])
        if(equal(snow[i],a))
            return 1;
    ++tot;
    memcpy(snow[tot], a,6 * sizeof(int));
    Next[tot] = head[val];
    head[val] = tot;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a[10];
        for(int i=0;i<6;i++)
            scanf("%d",&a[i]);
        if (insert(a)){
            printf("Twin snowflakes found.\n");
            return 0;
        }

    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
