#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx; //链表相关
bool st[N];                 //记录每一个点是否被遍历过

int ans = N; //ans是最后要到找的‘最小值’，故先初始化为最大

void add(int a, int b) //添加一个a->b 链表操作
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//返回以u为根的子树中点的数量
int dfs(int u)
{
    st[u] = true; //标记，这个点已经被搜索过了

    int sum = 1, res = 0;                  //res表示当前节点被删除后剩下的子树的节点最大值
    for (int i = h[u]; i != -1; i = ne[i]) // 遍历每一个查询节点的所有子结点
    {
        int j = e[i]; //拿出链表中对应节点的值
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s; //更新树的大小  ===  1 + 左子树 + 右子树
        }
    }
    res = max(res, n - sum); //别忘了除了被删除节点的左右子树之外的集合
    ans = min(ans, res);     //更新答案
    return sum;
}

int main()
{
    cin >> n;

    memset(h, -1, sizeof h); //头结点都初始化为-1
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); //无向图，所以建立双向连接
    }
    dfs(1); //从第一个点开始

    cout << ans << endl; //输出全局答案
}
