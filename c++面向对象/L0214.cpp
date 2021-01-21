#include<iostream>

int aver = 10;
int main(){
    int aver;
    std::cin >> aver;
    std::cout << "local avar=" << aver << std::endl;
    std::cout << "global avar=10";
    return 0;
}