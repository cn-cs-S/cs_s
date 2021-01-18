#include<iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << "a=" << a << ",b=" << b << std::endl;
    swap(a, b);
    std::cout << "After swap:";
    std::cout << "a=" << a << ",b=" << b << std::endl;
}