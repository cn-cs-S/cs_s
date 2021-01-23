#include<iostream>

double sum(double &x, double &y) {
    return x + y;
}

int main(){
    double x, y;
    std::cin >> x >> y;
    std::cout << x << '+' << y << '=' << sum(x, y);
    return 0;
}