#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void input(void)
{

    for (int i = 0; i < 12; i++)
    {
        printf("%3.1lf ", (double)(rand() % 91 + 10) / 10);
    }
    return;
}
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % 50 + 10;
    printf("%d\n", n);
    char x = 'A';
    for (int i = 0; i < n; i++)
    {
        printf("%c %c%c %c%c%c\n", x, x, x, x, x, x);
        x++;
    }
    getchar(); //交互
    for (int i = 0; i < n; i++)
    {
        input();
        printf("\n");
        printf("\n");
    }
}