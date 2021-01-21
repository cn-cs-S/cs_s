#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    int daan[100];
    cin >> n >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        daan[i] = 1;
        for (int k = n - 1; k >= 0; k--)
        {
            char c = getchar();
            if (c == 'n')
            {
                daan[i] += pow(2, k);
            }
        }
        getchar();
    }
    for (int i = 0; i < m; i++)
    {
        cout << daan[i] << endl;
    }
    
    return 0;
}
