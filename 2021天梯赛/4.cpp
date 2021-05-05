#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        double p;
        cin >> p;
        if (p < m)
            printf("On Sale! %.1lf\n", p);
    }
    
}