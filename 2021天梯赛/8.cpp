#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a1, a2, n;
    cin >> a1 >> a2 >> n;
    vector<int> v;
    v.push_back(a1);
    v.push_back(a2);
    bool fir = true;
    for (int i = 0; i < n; i++)
    {
        int num = v[i] * v[i+1];
        if (num < 10)
            v.push_back(num);
        else
        {
            int a = num / 10;
            num -= a * 10;
            v.push_back(a);
            v.push_back(num);
        }

        if (fir) {
            fir = false;
            cout << v[i];
        }
            
        else
            cout << ' ' << v[i];
    }
    
}