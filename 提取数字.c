#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[1000];
    gets(str);
    int len = strlen(str);
    char *pstr = str;
    while (/*(*/ *(pstr++) /*= getchar())!='\n'*/)
    {
        if (!isdigit(*(pstr - 1)))
        {
            *(pstr - 1) = 0;
        }
    }
    pstr = str;
    //int temp=30;
    while (pstr != &str[len])
    {
        while (!*pstr && pstr != &str[len])
        {
            pstr++;
        }
        if (!*pstr)
        {
            break;
        }

        printf("%8d", atoi(pstr));
        while (*pstr && pstr != &str[len])
        {
            pstr++;
        }
        /*if (!--temp)
        {
            printf("\nerror\n");
            break;
        }*/
    }

    return 0;
}