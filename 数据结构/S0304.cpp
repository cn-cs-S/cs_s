#include <stdio.h>
int main()
{
    void hn(int n, char a, char b, char c);
    int m;
    scanf("%d", &m);
    hn(m, 'A', 'B', 'C');
    return 0;
}
void hn(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c-->%c\n", a, c);
    }
    else
    {
        hn(n - 1, a, c, b);
        printf("%c-->%c\n", a, c);
        hn(n - 1, b, a, c);
    }
    return;
}