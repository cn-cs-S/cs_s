
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int a[100], b[100];
    int result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i]) {
            ++result;
            continue;
        }
        if (a[i] == 0 && (b[i] == 2 || b[i] == 3))
        {
            ++result;
            continue;
        }
        if (a[i] == 1 && (b[i] == 3 || b[i] == 0))
        {
            ++result;
            continue;
        }
        if (a[i] == 2 && (b[i] == 4 || b[i] == 1))
        {
            ++result;
            continue;
        }
        if (a[i] == 3 && (b[i] == 4 || b[i] == 2))
        {
            ++result;
            continue;
        }
        if (a[i] == 4 && (b[i] == 0 || b[i] == 1))
        {
            ++result;
            continue;
        }
    }
    cout << result;
    return 0;
}