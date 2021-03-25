//https://www.acwing.com/solution/content/7977/

#include <iostream>

using namespace std;

const int N = 100010, M = 10010;

int m, n;
char p[N], s[N];

int ne[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    //求next的过程
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    //kmp匹配过程
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
        {
            j = ne[j];
        }
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            //匹配成功
            printf("%d", i - n + 1);
            j = ne[j];
        }
    }
    return 0;
}