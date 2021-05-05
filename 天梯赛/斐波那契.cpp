
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int64_t a = 2, b = 3;
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2;
        return 0;
    }
    if (n == 2)
    {
        cout << 3;
        return 0;
    }
    int ci = n - 2;
    for (int i = 0; i < ci; i++)
    {
        int64_t temp = b;
        b = a*3 + b*2 + 5;
        a = temp;
    }
    cout << b%19260817;
    return 0;
}