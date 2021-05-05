#include <iostream>
using namespace std;

int main()
{
    int time[24];
    for (int i = 0; i < 24; i++)
    {
        cin >> time[i];
    }
    int n;
    do{
        cin >> n;
        if (n > 23 || n < 0)
            break;
        cout << time[n] << ' ';
        if (time[n] > 50)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }while(1);
    
}