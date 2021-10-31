#include <iostream>
#include <cmath>

inline double max(double a, double b, double c)
{
    return a > b ? (a > c ? a : (b > c ? b : c)) : b > c ? b
                                                         : c;
}

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    double result = max(a, b, c);
    std::cout << "max=" << result;
}