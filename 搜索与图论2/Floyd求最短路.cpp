#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++) //模板
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n >> m >> Q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0; //删掉自环
            else
                d[i][j] = INF;

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w); //去除重边
    }

    floyd();

    while (Q--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2) //无穷大也可能被更新
            puts("impossible");
        else
            cout << d[a][b] << endl;
    }
    return 0;
}