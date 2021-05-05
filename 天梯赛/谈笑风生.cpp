
#include <iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    char c;
    cin.clear();
    c = getchar();
    int sum = 0;
    for (auto r : str) {
        if (r == c)
            sum++;
    }
    cout << sum;
    return 0;
}