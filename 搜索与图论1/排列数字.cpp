#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N]; //存储每一种结果
bool st[N];  //表示每一个数字是否被使用过

void dfs(int x)
{
    if (x == n) //表示一种结果已经出现
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= n; i++) //遍历所有可用的数
    {
        if (!st[i]) //只使用没有用过的数
        {
            path[x] = i;   //将这个数字加入路径
            st[i] = true;  //已经用过了
            dfs(x + 1);    //查找下一层
            st[i] = false; //恢复现场
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);

    return 0;
}