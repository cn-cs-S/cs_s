#include <iostream>

inline double f(double a, double b, double c) {
    return a * b * c;
}

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double result = f(a, b, c);
    std::cout << result;
}