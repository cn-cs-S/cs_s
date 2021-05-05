
#include <iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int result[26];
    for (int i = 0; i < 26; i++)
    {
        result[i] = 0;
    }
    getchar();
    while (n)
    {
        char c = getchar();
        if (c >= 'A' && c <= 'Z')
            result[int(c-'A')]++;
        if (c == '\n')
            n--;
    }
    
    int most = result[0];
    for (int i = 1; i < 26; i++)
    {
        if (result[i] > most)
            most = result[i];
    }

    for (int i = most; i > 0 ; i--)
    {
        for (int t = 0; t < 26; t++)
        {
            if (i <= result[t])
                putchar('*');
            else
                putchar(' ');
            putchar(' ');
        }
        
        putchar('\n');
        
    }
    for (int i = 0; i < 26; i++)
    {
        putchar('A'+i);
        putchar(' ');
    }
    
    
    return 0;
}