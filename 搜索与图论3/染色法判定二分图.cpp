#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N]; //记录每个点的颜色， 0-未染色 1-颜色1 2-颜色2

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//给每个点所在的联通块染色，并返回染色是否成功
bool dfs(int u, int c)
{
    color[u] = c;                          //先给u染色
    for (int i = h[u]; i != -1; i = ne[i]) //再根据u的颜色给连通块内剩余的点染色
    {
        int j = e[i];
        if (!color[j]) //如果j没有染过色
        {
            if (!dfs(j, 3 - c)) //如果染色失败
                return false;
        }
        else if (color[j] == c) //如果j已经染过色了，并且颜色和u一样，说明染色失败；
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true; //表示染色是否成功
    for (int i = 1; i <= n; i++)
        if (!color[i]) //如果还没有染色
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    if (flag) //说明可以染成两种颜色，即原图是二分图
        puts("Yes");
    else
        puts("No");
    return 0;
}
