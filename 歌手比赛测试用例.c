#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(void)
{
    for (int i = 0; i < 12; i++)
    {
        printf("%3.1lf ",(double)(rand()%91+10)/10);
    }
    return ;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        input();
        printf("\n");
        printf("\n");
    }
    
}