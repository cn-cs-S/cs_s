#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int qian, hou;
        qian = str[0] + str[1] + str[2] - '0'*3;
        hou = str[3] + str[4] + str[5] - '0' * 3;
        if (qian == hou) {
            cout << "You are lucky!" << endl;
        }
        else
            cout << "Wish you good luck." << endl;
    }
    
}