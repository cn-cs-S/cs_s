
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    int is = 0;
    if (num % 2 == 0)
        is++;
    if (num > 4 && num < 16)
        is++;
    if (is == 2)
        cout << 1 << ' ';
    else
        cout << 0 << ' ';
    if (is >= 1)
        cout << 1 << ' ';
    else
        cout << 0 << ' ';
    if (is == 1)
        cout << 1 << ' ';
    else
        cout << 0 << ' ';
    if (is == 0)
        cout << 1;
    else
        cout << 0;
    return 0;
}