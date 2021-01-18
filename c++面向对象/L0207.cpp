#include<iostream>

int sum(int x, int y){
    return x + y;
}

int main(){
    int x, y;
    std::cin >> x >> y;
    std::cout << x << '+' << y << '=' << sum(x, y);
}