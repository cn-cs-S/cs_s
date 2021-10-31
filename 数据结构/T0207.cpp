#include <iostream>
#include <string>
#include <time.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define Status int
#define ElemType string
using namespace std;

typedef struct LinkNode
{
    LinkNode *next;
    ElemType data;
} * LinkList;

void InitList(LinkList &L)
{
    L = new LinkNode;
    L->next = NULL;
}

void showList(const LinkList &L)
{
    if (!L->next)
    {
        cout << "empty!" << '\n';
        return;
    }
    LinkList p = L->next;
    int i = 1;
    while (p)
    {
        cout << i++ << ":" + p->data << '\n';
        p = p->next;
    }
}

Status CreateList_R(LinkList &L, int number)
{
    LinkNode *end = L;
    while (end->next != NULL)
        end = end->next;
    for (int i = 0; i < number; i++)
    {
        LinkNode *node = new LinkNode;
        cin >> node->data;
        node->next = end->next;
        end->next = node;
        end = node;
    }

    return OK;
}

// void Inverse(LinkList &l)
// {
//     LinkNode *h = l->next;
//     while (h->next)
//     {
//         LinkNode *t = h->next;
//         h->next = t->next;
//         t->next = l->next;
//         l->next = t;
//     }
// }

void Inverse(LinkList &l)
{
    LinkList m = new LinkNode;
    LinkList t = l;
    while (t = t->next)
    {
        // 0 - 1 - 2 ...
        


        // LinkNode *n = new LinkNode;
        // n->data = t->data;
        // n->next = m->next;
        // m->next = n;
        // delete t;
        // 创建结点
        // 插到m的后面
        // 释放原来的空间
        // l = m
    }

    l = m;
    
}

int main()
{
    LinkList Lscore;
    InitList(Lscore);        //初始化单链表
    showList(Lscore);        //单链表遍历
    CreateList_R(Lscore, 4); //后插法创建单链表
    showList(Lscore);
    Inverse(Lscore);
    cout << "After inversing:" << endl;
    showList(Lscore); //单链表遍历
    return 0;
}