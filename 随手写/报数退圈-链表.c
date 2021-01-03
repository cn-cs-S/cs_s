#include <stdio.h>
#include <stdlib.h>

typedef struct people       //&双向链表Z
{
    int id;
    struct people *pre;
    struct people *next;
} people;

const int len = sizeof(people);     //防止重复计算

people *creat(const int m)          //&创建循环链表
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
    while (head->next!=head)
    {
        head=head->next->next;
        people *temp=head;
        head->pre->next=head->next;
        head->next->pre=head->pre;
        free(temp);
        temp=NULL;
        head=head->next;
    }
    return head->id;
}

/*
int print(people *head)     //&退圈
{
    static int num = 0;     //?越长越好看系列
    while (head->next != head)  //^当只剩一个人的时候指向的应该是自己
    {
        if (++num % 3 == 0)     //^退圈
        {
            people *temp = head;    //临时变量用于free
            head->pre->next = head->next;//上一个元素指向下一个
            head->next->pre = head->pre;//下一个元素指向上一个
            head = head->next;//移动指针
            free(temp);       //!释放内存,要给释放的内存赋NULL
            temp = NULL;      
            continue;
        }
        head = head->next;
    }
    return head->id;        //返回剩下的id
}
*/

int main(void)
{
    const int m = 100;    //?越长越好看系列
    people *head = creat(m);
    printf("%d\n", print(head));
    return 0;
}