#include <iostream>

using namespace std;

const int N = 10010;

int n, m;
int p[N], size1[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        size1[i] = 1;
    }
    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op;

        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b))
                continue;
            size1[find(b)] += size1[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            cin >> a;
            cout << size1[find(a)] << endl;
        }
    }

    return 0;
}