#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str.size() == 6) {
        for (int i = 0; i < 4; i++)
        {
            cout << str[i];
        }
        cout << '-';
        for (int i = 4; i < 6; i++)
        {
            cout << str[i];
        }
        
    }
    else
    {
        if ((str[0]-'0')*10 + str[1] - '0' < 22){
            cout << "20";
            for (int i = 0; i < 2; i++)
            {
                cout << str[i];
            }
            cout << '-';
            for (int i = 2; i < 4; i++)
            {
                cout << str[i];
            }
            
        }
        else
        {
            cout << "19";
            for (int i = 0; i < 2; i++)
            {
                cout << str[i];
            }
            cout << '-';
            for (int i = 2; i < 4; i++)
            {
                cout << str[i];
            }
                }
    }
}