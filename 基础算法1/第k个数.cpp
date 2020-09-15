// https://www.acwing.com/problem/content/788/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, k;
int q[N];

int find_k_min(int q[], int l, int r, int k)
{
    if (l >= r)
        return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    int s = j - l + 1; //
    if (s >= k)
        find_k_min(q, l, j - 1, k);
    else
        find_k_min(q, j + 1, r, k - s);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    cout << find_k_min(q, 0, n - 1, k);

    return 0;
}