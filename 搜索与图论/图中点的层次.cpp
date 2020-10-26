#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx; //用邻接表表示图  链表模拟邻接表
int d[N], q[N];             //d[i]表示第i个点到初始点的距离  q 是bfs算法需要的的队列

void add(int a, int b) //链表的基本操作，模拟添加两个节点之间的一条边
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//返回最终结果
int bfs()
{
    int hh = 0, tt = -1;     //队列初始化
    q[++tt] = 1;             //把第一个点加入队列
    memset(d, -1, sizeof d); //d表示距离，为-1时表示这个点还没有遍历过

    d[1] = 0; //第一个节点到第一个节点的距离为1
    while (hh <= tt)
    {
        int t = q[hh++];                       //拿出队头的一个点
        for (int i = h[t]; i != -1; i = ne[i]) //遍历其所有的一级子结点
        {
            int j = e[i];   //取出点
            if (d[j] == -1) //这个点应该没有被遍历过
            {
                d[j] = d[t] + 1; //距离+1
                q[++tt] = j;     //把这个点加入队尾
            }
        }
    }
    return d[n]; //循环结束后，d[n】就为最终结果
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); //无向图
    }
    cout << bfs() << endl;

    return 0;
}
