#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;          //记录每个数出现的次数
        while (s[a[i]] > 1) //如果数字重复
        {
            s[a[j]]--; //j向右移，缩短区间长度，数字出现次数减一
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;

    return 0;
}
