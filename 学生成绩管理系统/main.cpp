#include<iostream>
#include<string>
#include<vector>
#include"Student.hpp"
#include"System.hpp"
int main(int argc, char const *argv[])
{
    using namespace std;
    std::vector <Student> Students;
    cout << Students.begin()->setCLanguage(65).getCLanguage() << endl;
    return 0;
}
