#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int n, m;
int h[N], ph[N], hp[N], size1;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size1 && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= size1 && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
        heap_swap(u, t);
    down(t);
}
void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main()
{
    int n, m = 0;
    cin >> n;
    while (n--)
    {
        char op[10];
        int k, x;
        cin >> op;
        if (!strcmp(op, "I"))
        {
            cin >> x;
            size1++;
            m++;
            ph[m] = size1, hp[size1] = m;
            h[size1] = x;
            up(size1);
        }
        else if (!strcmp(op, "PM"))
            cout << h[1] << endl;
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, size1);
            size1--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, size1);
            size1--;
            down(k), up(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}