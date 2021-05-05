#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    x = 100-x;
    int result = 5000 - 100*x/2 - 100*y/2;
    cout << result;
}