#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}
void add_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
void add_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if (op == 'I')
        {
            cin >> k >> x;
            add_k(k - 1, x);
        }
        else
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;
    return 0;
}