#include<stdio.h>
void sort(int *p,int n)
{
    int i=0;
    int t;
    while ((p+i++)<=(p+n-1-i++))
    {
        t=*(p+i++);
        *(p+i++)=*(p+n-1-i++);
        *(p+n-1-i++)=t;
    }
}
