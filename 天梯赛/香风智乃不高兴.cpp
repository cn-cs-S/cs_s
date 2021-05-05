#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int days = 0;
    int day[7];
    int most = 0;
    int m = 0;
    int a, b;
    for (int i = 0; i < 7; i++)
    {
        cin >> a >> b;
        int sum = a + b;
        if (sum > 8) {
            day[days++] = i + 1;
            if (sum >= m)
                m = sum;
                most = i + 1;
        }
    }
    cout << days << endl;
    for (int i = 0; i < days; i++)
    {
        cout << day[i] << ' ';
    }
    cout << endl;
    cout << most;
    
    
    return 0;
}
