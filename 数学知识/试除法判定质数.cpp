#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n / i; i++) //速度快，不会溢出
        if (n % i == 0)
            return false;
    return true;
}
