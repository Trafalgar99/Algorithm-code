#include <vector>

using namespace std;

class Solution
{
public:
    int d[1000][1000] = {-1};

    pair<int, int> q[1000 * 1000];
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int hh = 0, tt = 0;
        int n = matrix.size();
        vector<vector<int>> ans(n);
        q[0] = {0, 0};
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (hh <= tt)
        {
            auto t = q[hh++];
            for (int i = 0; i < 4; i++)
            {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < n && d[x][y] == -1)
                {
                    if (matrix[x][y] == 0)
                    {
                        d[x][y] = 0;
                        d[t.first][t.second] = 0 + matrix[t.first][t.second];
                    }
                    else
                    {
                        d[t.first][t.second] = d[t.first][t.second] + matrix[x][y];
                    }
                    q[++tt] = {x, y};
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] == -1)
                    d[i][j] = 0;
                ans[i].push_back(d[i][j]);
            }
        return ans;
    }
};