#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string start)
{
    string end = "12345678x";
    queue<string> q;
    q.push(start);
    unordered_map<string, int> d;
    d[start] = 1;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t == end)
            return d[t];

        int distance = d[t];

        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t))
                {
                    q.push(t);
                    d[t] = distance + 1;
                }
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
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
}