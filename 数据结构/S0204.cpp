#include <iostream>
#include <string>
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

Status CreateList_H(LinkList &L, int number)
{
    for (int i = 0; i < number; i++)
    {
        LinkNode *node = new LinkNode;
        cin >> node->data;
        node->next = L->next;
        L->next = node;
    }

    return OK;
}

int main()
{
    LinkList Lname;
    InitList(Lname);        //初始化单链表
    showList(Lname);        //单链表遍历
    CreateList_H(Lname, 5); //前插法创建单链表
    showList(Lname);        //单链表遍历
    return 0;
}