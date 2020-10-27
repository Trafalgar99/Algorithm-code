#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string start)
{
    string end = "12345678x"; //结束状态
    queue<string> q;
    unordered_map<string, int> d;

    q.push(start); //初始状态
    d[start] = 0;  //起点到起点的距离是0

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //方向向量

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int distance = d[t];

        if (t == end) //已经找到最终结果
            return distance;

        //状态转移
        int k = t.find('x'); //字符串表示法与矩阵表示法的坐标转换
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++) //所有可能的下一步的状态
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) //这个点没有越界
            {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t)) //t这个状态是第一次出现
                {
                    d[t] = distance + 1; //更新距离
                    q.push(t);           //入队
                }
                swap(t[k], t[a * 3 + b]); //还原t的状态进行下一点的检测
            }
        }
    }
    return -1; //走到这里意味着没找到
}

int main()
{
    string start;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}