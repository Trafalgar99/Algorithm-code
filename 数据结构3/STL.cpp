#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //vector初始化
    vector<int> a(10, 3);
    a.size(); //所有容器都有 O(1)
    a.empty();

    return 0;
}