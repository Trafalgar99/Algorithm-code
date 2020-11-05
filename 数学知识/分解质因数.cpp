#include <iostream>
#include <algorithm>

using namespace std;

void divide(int n)
{
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
        {
            int s = 0;
            while (n % i == 0)
            {
                n /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    if (n > 1)
        cout << n << " " << 1 << endl;
    puts("");
}