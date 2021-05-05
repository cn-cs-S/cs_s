
#include <iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string man[25], woman[25];
    int n;
    cin >> n;
    int m = 0, w = 0;
    int sex[50];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin.clear();
        int c;
        cin >> c;
        string name;
        cin >> name;
        sex[s++] = c;
        if (c == 0) {
            woman[w++] = name;
        }
        else
            man[m++] = name;
        
    }
    int wb = 0, we = n/2-1;
    int mb = 0, me = n/2-1;
    for (int i = 0; i < n/2; i++)
    {
        if (sex[i] == 0) {
            cout << woman[wb++]  << ' ' << man[me--] << endl;
        }
        else
            cout << man[mb++] << ' ' << woman[we--] << endl;
    }
    
    return 0;
}