#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    int sum = 0;
    int huo = 0;
    int fir = 0;
    
    while (getline(cin, str))
    {
        if (str == ".")
        {
            break;
        }
        sum++;
        if (str.find("chi1 huo3 guo1") != -1)
        {
            if (!fir)
            {
                fir = sum;
            }
            huo++;
        }
    }
    cout << sum << endl;
    if (huo)
    {
        cout << fir << ' ' << huo;
    }
    else
        cout << "-_-#";
    return 0;
}