#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const //要用sort排序结构体，所以要重载小于号运算符
    {
        return w < W.w;
    }
} edges[N];
int find(int x) //并查集的操作
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) //并查集初始化
        p[i] = i;
    int res = 0, cnt = 0;       //当前加入多少条边
    for (int i = 0; i < m; i++) //枚举每一条边
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) //说明这个图不连通
        puts("impossible");
    else
        cout << res << endl;
}
