#include<iostream>
#include<cmath>

int main(){
    std::printf("%.2lf", pow(1.01, 365) / pow(0.99, 365));
    return 0;
}