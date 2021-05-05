#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    int num = 'A' - 'a';
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        
        cout << str << endl;
        for (auto &r: str) {
            if (r >= 'A' && r <= 'Z' && r != 'I') {
                r = r - num;
            }
        }
        str = regex_replace(str, regex("(^\\s*)|(\\s*$)"), "");
        str = regex_replace(str, regex("  +"), " ");
        str = regex_replace(str, regex(" *([^a-z]I[^a-z])|([^a-z]me[^a-z]) *"), " you ");
        str = regex_replace(str, regex(" *can you *"), "I can ");
        str = regex_replace(str, regex(" *could you *"), "I could ");
        str = regex_replace(str, regex("\\?"), "!");
        

        cout << "AI: " << str << endl;
    }
    
}