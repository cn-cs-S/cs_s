#include<iostream>
using namespace std;

int main(){
    int num[1000];
    char cr[1000];
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0; i < n - 1; i++)
        cin >> cr[i];

    for (int i = n - 2; i >= 0; i--)
    {
        if (cr[i] == '+')
        {
            num[i] = num[i] + num[i+1];
            continue;
        }
        if (cr[i] == '*')
        {
            num[i] = num[i] * num[i+1];
            continue;
        }
        if (cr[i] == '-')
        {
            num[i] = num[i] - num[i+1];
            continue;
        }
        if (cr[i] == '/')
        {
            if (num[i+1] == 0)
            {
                cout << "ERROR: " << num[i] << '/' << num[i+1];
                return 0;
            }
            num[i] = num[i] / num[i+1];
            continue;
        }
    }
    cout << num[0];
    return 0;
}