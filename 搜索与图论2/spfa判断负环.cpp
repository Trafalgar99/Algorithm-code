#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 150010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N], cnt[N]; //cnt[i]为i到1的最短路路径上的边的数量
int st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int spfa()
{
    queue<int> q; //队列存储路径变短的点

    //为了找到初始点到达不了的负环，需要一开始就把所有点都放到队列里
    for (int i = 1; i <= n; i++)
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) //尝试用路径已经变短的点去更新它的临边
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; //更新最短路的边数

                if (cnt[j] >= n)
                    return true; //如果最短上的边数已经大于n了，则一定有负环

                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}