#include<iostream>
#include<string>

int main(){
    std::cout << "Hello,your name:" <<std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::cout << "My name is " + str;
    return 0;
}