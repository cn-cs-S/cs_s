#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cen = log2(N+1) + 1;
    int top = cen*2 - (pow(2, cen)-1 - N);
    int fir = 0, sec = 0, thi = 0, fot = 0, fif = 0;
    int first[30];
    int second[30];
    int third[30];
    int forth[30];
    int fifth[30];
    int num;
    int one, two, three, four;
    one = two = three = four = 0;
    for (int i = 0; i < N; i++)
    {
        if (four == 2)
        {
            cin >> num;
            fifth[fif++] = num;
            four = 0;
            continue;
        }
        if (three == 2)
        {
            cin >> num;
            forth[fot++] = num;
            four++;
            three = 0;
            continue;
        }
        if (two == 2)
        {
            cin >> num;
            third[thi++] = num;
            three++;
            two = 0;
            continue;
        }
        if (one == 2 || (fir == top))
        {
            cin >> num;
            second[sec++] = num;
            two++;
            one = 0;
            continue;
        }
        if (fir != top)
        {
            cin >> num;
            first[fir++] = num;
            one++;
        }
    }
    int leap = 1;
    for (int i = 0; i < fif; i++)
    {
        if (leap)
        {
            cout << fifth[i];
            leap = 0;
            continue;
        }
        cout << ' ' << fifth[i];
    }
    for (int i = 0; i < fot; i++)
    {
        if (leap)
        {
            cout << forth[i];
            leap = 0;
            continue;
        }
        cout << ' ' << forth[i];
    }
    for (int i = 0; i < thi; i++)
    {
        if (leap)
        {
            cout << third[i];
            leap = 0;
            continue;
        }
        cout << ' ' << third[i];
    }
    for (int i = 0; i < sec; i++)
    {
        if (leap)
        {
            cout << second[i];
            leap = 0;
            continue;
        }
        cout << ' ' << second[i];
    }
    for (int i = 0; i < fir; i++)
    {
        if (leap)
        {
            cout << first[i];
            leap = 0;
            continue;
        }
        cout << ' ' << first[i];
    }
    return 0;
}