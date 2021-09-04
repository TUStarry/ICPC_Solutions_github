#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
struct SBTNode{
    int val;
    int key; 
    int size;
    int son[2];
    void init(int _val, int _size, int _key){
        val = _val, size = _size, key = _key, son[0] = son[1] = 0;
    }
};
struct SBTTree{
    int tot, root;
    SBTNode tr[maxn];
    void init() {//初始化
        tot = 0, root =  0;
        tr[0].init(0, 0, 0);
    }
    void update(int p) {//更新节点下子节点数量
        tr[p].size = tr[tr[p].son[0]].size + tr[tr[p].son[1]].size + 1;
    }
    void rotate(int &x, int p){//旋转
        int y = tr[x].son[!p];
        tr[x].son[!p] = tr[y].son[p];
        tr[y].son[p] = x;
        update(x), update(y);
        x = y;
    }
    void maintain(int &x, int p){//维护
        if(tr[tr[tr[x].son[p]].son[p]].size > tr[tr[x].son[!p]].size) rotate(x, !p);
        else if(tr[tr[tr[x].son[p]].son[!p]].size > tr[tr[x].son[!p]].size) rotate(tr[x].son[p], p), rotate(x, !p);
        else return;
        maintain(tr[x].son[0], 0);
        maintain(tr[x].son[1], 1);
        maintain(x, 0);
        maintain(x, 1);
    }
    void insert(int &x, int val, int key){//插入节点
        if(x == 0) tr[x = ++tot].init(val, 1, key);
        else{
            tr[x].size++;
            int p = val > tr[x].val;
            insert(tr[x].son[p], val, key);
            maintain(x, p);
        }
    }
    void del_node(int &x, int val){//删除节点
        if(tr[x].val == val)
        {
            if(tr[x].son[0] && tr[x].son[1])
            {
                int y = get_pre(x);
                tr[x].val = tr[y].val;
                tr[x].size--;
                del_node(tr[x].son[0], tr[x].val);
            }
            else x = tr[x].son[0] + tr[x].son[1];
        }
        else
        {
            tr[x].size--;
            int p = val > tr[x].val;
            del_node(tr[x].son[p], val);

        }
    }
    int get_pre(int x){//返回前驱的下标
        int y = tr[x].son[0];
        while(tr[y].son[1]) y = tr[y].son[0];
        return y;
    }
    int get_sub(int x){//返回后继的下标
        int y = tr[x].son[1];
        while(tr[y].son[0]) y = tr[y].son[0];
        return y;
    }
    int get_kth(int x, int k){//第k大
        if(k == tr[tr[x].son[0]].size + 1) return tr[x].val;
        else if(k > tr[tr[x].son[0]].size + 1) return get_kth(tr[x].son[1], k);
        else return get_kth(tr[x].son[0], k);
    }
    int get_rank(int x, int val){//获得val从小到大的排名
        if(val == tr[x].val) return tr[tr[x].son[0]].size + 1;
        else if(val > tr[x].val) return get_rank(tr[x].son[1], val) + tr[tr[x].son[0]].size + 1;
        else return get_rank(tr[x].son[0], val);
    }
    int get_min_max(int x, int p) {//得到最大值或者最小值
        while(tr[x].son[p]) x = tr[x].son[p];
        return x;
    }
}sbt;

int main()
{
    int op, k, p;
    sbt.init();
    while(scanf("%d", &op) != EOF && op)
    {
        if(op == 1){
            scanf("%d%d", &k, &p);
            sbt.insert(sbt.root, p, k);
        }
        else if(op == 2){
            int x= sbt.get_min_max(sbt.root, 1);
            printf("%d\n", sbt.tr[x].key);
            sbt.del_node(sbt.root, sbt.tr[x].val);
        }
        else{
            int x = sbt.get_min_max(sbt.root, 0);
            printf("%d\n", sbt.tr[x].key);
            sbt.del_node(sbt.root, sbt.tr[x].val);
        }
    }
    return 0;
}