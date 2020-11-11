#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N]; //v[i]表示每件物品的体积，w[i]表示每件物品的价值（权重）
int f[N];       // f[i][j]表示前i个物品中，满足所取的物品体积不大于j的所有取法的集合中，所取的物品的总价值的最大值

// int main()
// {
//     cin >> n >> m; //读入数据，物品数量n 背包容量m
//     for (int i = 1; i <= n; i++)
//         cin >> v[i] >> w[i];

//     //f[0][0~m]=0
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             f[i][j] = f[i - 1][j];
//             if (j >= v[i])
//                 f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//         }
//     cout << f[n][m] << endl;
//     return 0;
// }

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}