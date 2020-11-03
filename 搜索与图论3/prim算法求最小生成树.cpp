#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; //由于是稠密图，所以用邻接矩阵存储边
int dist[N]; //每个点相对于当前集合的最短距离
bool st[N];  //保存某一个点有没有加入到集合

int prim()
{
    memset(dist, 0x3f, sizeof dist); //初始化距离

    int res = 0;                //用来保存最终结果
    for (int i = 0; i < n; i++) //循环n次
    {
        int t = -1;
        for (int j = 1; j <= n; j++) //找到没有加入集合里的并且距离集合的距离最近的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) //如果不是第一个点，但是不存在存在距离不是无穷大的点
            return INF;          // 无最小生成树
        if (i)                   //第一个点加入集合的时候不用添加边的信息
            res += dist[t];

        st[t] = true;                //这个点已经加入集合了
        for (int j = 1; j <= n; j++) //用这个点更新其他点到集合的最近距离
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if (t == INF)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}