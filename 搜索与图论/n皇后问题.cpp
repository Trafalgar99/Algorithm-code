#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];                 //存储结果的网格
bool col[N], deg[N], udeg[N]; // 每一行，正对角线，反对角线，是否可以用

//按行查找
void dfs(int x)
{
    if (x == n) // 输出一组结果
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) //在一行内按列查找
    {
        if (!col[i] && !deg[x + i] && !udeg[n - x + i])
        {
            g[x][i] = 'Q';
            col[i] = deg[x + i] = udeg[n - x + i] = true;
            dfs(x + 1);
            col[i] = deg[x + i] = udeg[n - x + i] = false; //恢复现场
            g[x][i] = '.';
        }
    }
}

int main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}