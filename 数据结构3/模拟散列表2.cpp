//开放寻址法

#include <iostream>
#include <string.h>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f; //二十万零三是大于二十万的第一个质数

int h[N]; //

int find(int x)
{
    int k = (x % N + N) % N;

    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N)
            k = 0;
    }
    return k;
}

int main()
{
    int n;
    cin >> n;

    memset(h, 0x3f, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        int k = find(x);
        if (*op == 'I')

            h[k] = x;

        else
        {
            if (h[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }
    getchar();
    getchar();
    return 0;
}
