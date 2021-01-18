#include<iostream>

int main(){
    double x;
    while (std::cin >> x)
        std::cout << 2 << '*' << x << '=' << x * 2;
    return 0;
}