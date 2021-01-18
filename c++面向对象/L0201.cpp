#include<iostream>

int main(){
    std::cout << "Please input two integers:" << std::endl;
    int x, y;
    std::cin >> x >> y;
    std::cout << x << '+' << y << '=' << x + y;
    return 0;
}