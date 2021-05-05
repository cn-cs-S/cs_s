#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    int n;
    cin >> n;
    regex reg2("([a-z]*) ([a-z]*) ([a-z]*)[.]");
    string s = "qiao ben zhong.";
    getchar();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        int index1 = str.find(',');
        int index2 = str.find('.');
        if (str[index1-1] == 'g' && str[index1-2] == 'n' && str[index1-3] == 'o') {
            if (str[index2 - 1] == 'g' && str[index2 - 2] == 'n' && str[index2 - 3] == 'o'){
                string ss = regex_replace(str, reg2, s);
                cout << ss << endl;
            }
            else
                cout << "Skipped" << endl;
        }
        else
            cout << "Skipped" << endl;

    }
    
}