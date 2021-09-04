#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 10;
struct Node{
	int x;
	int y;
	int temp;
};
bool mp[maxn][maxn];
int fangxiang[8][2]={-2,-1, -1,-2, -2,1, 1,-2, -1,2, 2,-1, 1,2, 2,1};
int bfs(int startox, int startoy, int tox, int toy)
{
	memset(mp, false, sizeof(mp));
    queue<Node> node;
    node.push(Node{startox,startoy,0});
    mp[startox][startoy] = true;
    while(node.size())
    {
        Node front = node.front(); node.pop();
        if(front.x == tox && front.y == toy) return front.temp;
        for(int i=0;i<8;i++)
        {
            int fx = front.x + fangxiang[i][0];
            int fy = front.y + fangxiang[i][1];
            if(fx>8 || fx<=0 || fy>8 || fy<=0 ) continue;
            if(fx==tox && fy==toy) return front.temp + 1;
            if(!mp[fx][fy]){
                mp[fx][fy] = true;
                node.push(Node{fx, fy, front.temp+1});
            }
        }
    }

}
int main()
{
	char ch1, ch2;
	int a, b;
	while(scanf("%c%d %c%d%*c", &ch1, &a, &ch2, &b)!=EOF)
		printf("To get from %c%d to %c%d takes %d knight moves.\n", ch1, a, ch2, b, bfs(ch1-'a'+1, a, ch2-'a'+1, b));	
	return 0;
}
/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/