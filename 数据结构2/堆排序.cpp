#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], size1;

void down(int u)
{
    int t = u;
    if (u * 2 <= size1 && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= size1 && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
        swap(h[u], h[t]);
    down(t);
}
void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    size1 = n;
    for (int i = n / 2; i != 0; i--)
        down(i);

    while (m--)
    {
        cout << h[1];
        h[1] = h[size1];
        size1--;
        down(1);
    }

    return 0;
}