//给定一个字符串，将其每个单词输出

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[1000];
    gets(str);

    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && str[i] != ' ')
            j++;

        //这道题目的具体逻辑
        for (int k = i; k < j; k++)
            cout << str[k];
        cout << endl;

        i = j;
    }

    return 0;
}
