#include<iostream>

int square(int x){
    std::cout << x << '*' << x << '=' << x * x << std::endl;
    return x * x;
}

double square(double x){
    std::cout << x << '*' << x << '=' << x * x << std::endl;
    return x * x;
}

int main(){
    double x;
    while (std::cin >> x)
        square(x);
    return 0;
}