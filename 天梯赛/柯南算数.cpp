
#include <iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double a, n;
    cin >> a >> n;
    int result = pow(a, n);
    cout << result % 19260817;
     return 0;
}