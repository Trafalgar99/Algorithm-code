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
            cout << str[k];
        cout << endl;

        i = j;
    }

    return 0;
}