/*816 - Abbott's Revenge
---代码完全参考刘汝佳算法入门经典
---strchr() 用来查找某字符在字符串中首次出现的位置，其原型为：char * strchr (const char *str, int c)
---BFS求最短路
--*/
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 10;
struct Node{
    int r, c, dir;
    Node(int a=0, int b=0, int c=0) : r(a), c(b), dir(c){}
};

int dis[maxn][maxn][4];//dis[r][c][dir]保存状态(r,c,dir)到初始状态的距离
int id[256];
Node path[maxn][maxn][4]; //path[r][c][dir]保存了状态(r,c,dir)在BFS树中的父节点
int has[maxn][maxn][4][3];//has[r][c][dir][turn]，表示当前处在(r,c,dir)状态是否可以向turn转弯
int r0, c0, r1, c1, r2, c2, dir;

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

//计算出下一个节点
Node walk(Node&u, int turn){
    //首先计算出下一步的朝向
    int dir = u.dir;
    if (turn == 1)dir = (dir + 3) % 4; //左转，逆时针
    if (turn == 2)dir = (dir + 1) % 4;//右转，顺时针
    return Node(u.r + dr[dir], u.c + dc[dir], dir);
}
bool insid(int r, int c){
    return r >= 1 && c >= 1 && r <= 9 && c <= 9;
}

void print_ans(Node u){
    vector<Node>vec;
    while (dis[u.r][u.c][u.dir] != 0){
        vec.push_back(u);
        u = path[u.r][u.c][u.dir];
    }
    vec.push_back(u);
    vec.push_back(Node(r0, c0, dir));
    int cnt = 0;
    printf("  ");
    for (int i = vec.size() - 1; i >= 0; i--,cnt++){
        if (cnt){
            if (cnt% 10 == 0)printf("\n  ");
            else printf(" ");
        }
        printf("(%d,%d)", vec[i].r, vec[i].c);
    }
    printf("\n");
}

void bfs(){
    queue<Node>Q;
    Node u(r1, c1, dir);
    Q.push(u);
    memset(dis, -1, sizeof(dis));
    dis[r1][c1][dir] = 0;
    while (!Q.empty()){
        u = Q.front(); Q.pop();
        if (u.r == r2&&u.c == c2){ print_ans(u); return; }
        for (int i = 0; i < 3; i++){
            Node v = walk(u, i);
            if (has[u.r][u.c][u.dir][i] && insid(v.r, v.c) && dis[v.r][v.c][v.dir] < 0){
                path[v.r][v.c][v.dir] = u;
                dis[v.r][v.c][v.dir] = dis[u.r][u.c][u.dir] + 1;
                Q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}
int main(){
    //0123代表NESW，顺时针方向
    id['N'] = 0;
    id['E'] = 1;
    id['S'] = 2;
    id['W'] = 3;
    //012代表转向
    id['F'] = 0;
    id['L'] = 1;
    id['R'] = 2;
    char s1[21], s2[21];
    while (scanf("%s", s1)&&strcmp(s1,"END")){
        printf("%s\n", s1);
        scanf("%d%d%s%d%d", &r0, &c0, s2, &r2, &c2);
        dir = id[s2[0]];
        r1 = r0 + dr[dir];
        c1 = c0 + dc[dir];
        memset(has, 0, sizeof(has));
        int r, c;
        while (scanf("%d", &r) && r){
            scanf("%d", &c);
            while (scanf("%s", s1) && strcmp(s1, "*")){
                for (int i = 1; i < strlen(s1); i++){
                    has[r][c][id[s1[0]]][id[s1[i]]] = 1;
                }
            }
        }
        bfs();
    }
    return 0;
}
