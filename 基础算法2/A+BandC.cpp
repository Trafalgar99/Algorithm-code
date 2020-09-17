//https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

// A>=B
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}
bool isNeg(string &s)
{
    if (s[0] == '-')
        return true;
    return false;
}
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    return C;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    //去除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
int main()
{
    int n;

    cin >> n;
    while (n--)
    {
        string a, b, c;
        vector<int> A, B, C;
        cin >> a >> b >> c;
        bool aIsNeg = isNeg(a), bIsNeg = isNeg(b);
        if (aIsNeg)
            a.replace(0, 1, "");
        if (bIsNeg)
            b.replace(0, 1, "");
        for (int i = a.size() - 1; i >= 0; i--)
            A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--)
            B.push_back(b[i] - '0');
        for (int i = c.size() - 1; i >= 0; i--)
            C.push_back(c[i] - '0');

        vector<int> AaB = add(A, B), AsB = sub(A, B);
        if (!aIsNeg && !bIsNeg)
    }

    return 0;
}