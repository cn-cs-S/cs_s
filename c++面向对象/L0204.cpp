#include<iostream>

int main(){
    int number;
    std::cin >> number;
    std::cout << std::dec << number << ' ';
    std::cout << std::oct << number << ' ';
    std::cout << std::hex << number;
    return 0;
}