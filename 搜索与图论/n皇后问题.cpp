#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], deg[N], udeg[N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !deg[x + i] && !udeg[n - x + i])
        {
            g[x][i] = 'Q';
            col[i] = deg[x + i] = udeg[n - x + i] = true;
            dfs(x + 1);
            col[i] = deg[x + i] = udeg[n - x + i] = false;
            g[x][i] = '.';
        }
    }
}

int main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    return 0;
}