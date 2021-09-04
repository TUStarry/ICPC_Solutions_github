#include<cstdio>
#include <cstring>
#include<stack>
using namespace std;
const int MAXN=1010;
int train[MAXN];
int main()
{
    int n,A,B,flag;
    while(scanf("%d",&n)&&n)
    {
        stack<int> s;
        while(1)
        {
        	scanf("%d",&train[1]);
        	if(train[1]==0)
                break;
            for(int i=2;i<=n;i++)
                scanf("%d",&train[i]);
        	A = B = flag = 1;
       	 	while(B <= n) //A是顺序结构
       	 	{
            	if(A==train[B]) //直接顺序进入
            	{
                    A++;
                    B++;
                }
            	else if(!s.empty() && s.top()==train[B]) //栈不为空，栈的顶部为
                {
                    s.pop();
                    B++;
                }
            	else if(A<=n)
                    s.push(A++);
            	else
                {
                    flag = 0;
                    break;
                }
       		}
        	printf("%s\n",flag?"Yes":"No");
		}
        printf("\n");
    }
	return 0;
}
