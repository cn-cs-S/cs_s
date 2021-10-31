#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void input(std::string *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }
}

void output(std::string *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << str[i] << std::endl;
    }
}

void sort(std::string *str, int n)
{
    std::sort(str, str + n);
}

int main()
{
    string str[5];
    int n = 5;
    input(str, n);
    sort(str, n);
    cout << "After sorting:" << endl;
    output(str, n);
    return 0;
}