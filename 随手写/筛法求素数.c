#include <stdio.h>
#include <string.h>
#define maxx 600

long long prime[maxx + 5];
long long num_prime = 0;
int book[maxx];
void quick_sushu(void)
{
    memset(book, -1, sizeof(book));
    book[0] = book[1] = 0;
    for (long long i = 0; i <= maxx; i++)
    {
        if (book[i] == -1)
        {
            prime[num_prime++] = i;
        }
        for (long long j = 0; j < num_prime && i * prime[j] <= maxx; j++)
        {
            book[i * prime[j]] = 0;
            if (!(i % prime[j]))
            {
                break;
            }
            
        }
    }
}

int main(void)
{
    quick_sushu();
    for (int i = 0; i < num_prime; i++)
    {
        printf("%lld ", prime[i]);
    }
    printf("\n");
    return 0;
}