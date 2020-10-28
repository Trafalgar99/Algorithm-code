#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; //邻接矩阵用于存储稠密图
int dist[N]; //存储每个点到原点的最近距离
bool st[N];  // 每个点是否已经找到最短路径

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //初始时的距离全部初始化为正无穷
    dist[1] = 0;                     //第一个点的距离初始点的距离为0

    for (int i = 0; i < n; i++) //迭代n次
    {
        int t = -1;
        for (int j = 1; j <= n; j++) //在所有st[i]==false的点里找到dist[i]最小的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (t == n)
            break;

        st[t] = true; //将这个点标记为已确定最短路径的点

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g); //初始化为正无穷

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); //读入每条边，但是只保留长度最短的边
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}