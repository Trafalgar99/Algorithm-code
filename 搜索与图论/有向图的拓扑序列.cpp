#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N]; //d[i]代表i的入度

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topSort()
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++) //先将所有入度为0的点加入队列
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--; //移出这一条边
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    return tt == n - 1; //说明所有的点都已经进入队列，即表明这个图是一个有向无环图，存在拓扑序列
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++; //对应点的入度加一
    }
    if (topSort())
    {
        //队列里存的就是拓扑序列
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout << endl;
    }
    else
        puts("-1");

    return 0;
}