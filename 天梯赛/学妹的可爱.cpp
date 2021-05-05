
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int peo[100];
    int result[100];
    int most = 0;
    int m = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> peo[i];
        result[i] = 0;
        if (peo[i] > m) {
            m = peo[i];
            most = i + 1;
        }
        for (int t = 0; t < i; t++)
        {
            if (peo[i] > peo[t])
                result[t]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    cout << most;
    
    return 0;
}