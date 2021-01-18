#include<iostream>
#include<iomanip>
#include<string>

int main(){
    std::cout << "Please enter your name and age:" << std::endl;
    std::string name;
    int age;
    std::getline(std::cin, name);
    std::cin >> age;
    std::cout << "name:" + name + ",age=" << std::setw(5) << age;
    return 0;
}