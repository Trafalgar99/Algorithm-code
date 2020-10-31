#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 150010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
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
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q; //队列存储路径变短的点
    q.push(1);
    st[1] = true; //当前点是否已经在队列当中

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
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
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

    int t = spfa();
    if (t == -1)
        puts("impossible");
    else
        cout << dist[n] << endl;
    return 0;
}