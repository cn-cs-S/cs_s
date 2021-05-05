#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    auto b = str.begin();
    auto e = str.end()-1;
    bool zero = true;
    if (str[0] == '-')
        cout << '-';
    for (auto i = e; i >= b; i--)
    {
        if(zero)
            if(*i == '0') {
                continue;
            }
            else
                zero = false;
        if (*i == '-')
            continue;
        cout << *i;
        
    }
    
    return 0;
}
