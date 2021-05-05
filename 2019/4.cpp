#include <iostream>
using namespace std;

int main()
{
    double ti, shen;
    cin >> ti >> shen;
    double result = ti/(shen*shen);
    printf("%.1lf\n", result);
    if (result > 25)
        cout << "PANG";
    else
        cout << "Hai Xing";
}