#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    str = regex_replace(str, regex("(6666+)"), "27");
    str = regex_replace(str, regex("(6666666666+)"), "9");
    cout << str;
}