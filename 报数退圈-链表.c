#include <stdio.h>
#include <stdlib.h>
typedef struct people
{
    int id;
    struct people *pre;
    struct people *next;
} people;

const int len = sizeof(people);

people *creat(const int m)
{
    people *head, *end, *node;
    head = (people *)calloc(1, len);
    end = head;
    head->id = 1;
    for (int i = 2; i < m + 1; i++)
    {
        node = (people *)calloc(1, len);
        node->id = i;
        end->next = node;
        node->pre = end;
        end = node;
    }
    end->next = head;
    head->pre = end;
    return head;
}

int print(people *head)
{
    static int num = 0;
    while (head->next != head)
    {
        if (++num % 3 == 0)
        {
            people *temp = head;
            head->pre->next = head->next;
            head->next->pre = head->pre;
            head = head->next;
            free(temp);
            temp = NULL;
            continue;
        }
        head = head->next;
    }
    return head->id;
}

int main(void)
{
    const int m = 10000;
    people *head = creat(m);
    printf("%d\n", print(head));
    return 0;
}