#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N]; // 并查集中每个元素的父节点

//核心代码
int find(int x) //返回x所在集合的编号   （使用路径压缩优化）
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        p[i] = i; //初始时每个元素各自为一个集合

    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M')
            p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}