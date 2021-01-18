#include<iostream>

double product(double x, double y, double z){
    std::cout << x << '*' << y << '*' << z << '=' << x * y * z << std::endl;
    return x * y * z;
}

double product(double x, double y){
    std::cout << x << '*' << y << '=' << x * y << std::endl;
    return x * y;
}

int main(){
    double x, y, z;
    std::cin >> x >> y >> z;
    product(x, y);
    product(x, y, z);
    return 0;
}