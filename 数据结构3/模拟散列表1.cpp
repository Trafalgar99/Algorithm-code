//拉链法 https://www.acwing.com/solution/content/15765/

#include <iostream>
#include <string.h>

using namespace std;

const int N = 100003; //十万零三是大于十万的第一个质数

int h[N], e[N], ne[N], idx; //

void insert(int x)
{
    int k = (x % N + N) % N; //保证结果一定是正数
    e[idx] = x;
    ne[idx] = h[k]; //h[k]存的是k对应的链的第一个元素的数组下标
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) // i!=-1  ,在第一次插入时，第一个节点的ne被置为1
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    int n;
    cin >> n;

    memset(h, -1, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        cin >> op >> x;

        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
    getchar();
    getchar();
    return 0;
}
