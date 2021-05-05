#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    bool leap = true;
    cin >> n >> m;
    int num = 0;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        
        if (str.find("easy") != -1 || str.find("qiandao") != -1)
            continue;
        else {
            num++;
        }
        if (num > m && leap) {
            cout << str;
            leap = false;
        }
    }
    if (leap) {
        cout << "Wo AK le";
    }
}