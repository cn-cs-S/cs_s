#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int N;
    int n;
    int num;
    char c;
    cin >> N;
    getchar();
    c = getchar();
    n =sqrt((N + 1) / 2);
    num = N - (2 * n * n - 1);
    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < n - i; j++)
                putchar(' ');
        for (int t = 0; t < 2 * i - 1; t++) 
            putchar(c);
        putchar('\n');
    }
    for (int i = 0; i < n - 1; i++)
        putchar(' ');
    
    putchar(c);
    putchar('\n');
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < n - i; j++)
                putchar(' ');
        for (int t = 0; t < 2 * i - 1; t++)
            putchar(c);
        putchar('\n');
    }
    cout << num;
    return 0;
}