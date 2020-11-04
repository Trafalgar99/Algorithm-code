#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N]; //2集合里匹配的1集合里的点的编号
bool st[N];   //2集合里的每个点是否已经被查询过

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[true];
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; i++) //遍历1集合所有点
    {
        memset(st, false, sizeof st); //每次遍历每个点的时候让st都为false
        if (find(i))                  //匹配成功
            res++;
    }
    cout << res << endl;

    return 0;
}
