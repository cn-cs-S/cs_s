#include <iostream>
#include <string>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define Status int
#define ElemType int
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
        cout << i++ << ":" << p->data << '\n';
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

void Decompose(LinkList &la, LinkList &lb, LinkList &lc)
{
    LinkList t = la;
    while (t = t->next)
    {
        LinkNode *temp = new LinkNode;
        temp->data = t->data;
        temp->data < 0 ? (temp->next = lb->next, lb->next = temp) : (temp->next = lc->next, lc->next = temp);
    }
}

int main()
{
    LinkList La, Lb, Lc;
    InitList(La), InitList(Lb), InitList(Lc); //初始化单链表
    CreateList_H(La, 6);                      //前插法创建单链表
    showList(La);
    Decompose(La, Lb, Lc); //将La分别为两个链表Lb与Lc(前插法)
    cout << "Show Lb:" << endl;
    showList(Lb); //单链表遍历
    cout << "Show Lc:" << endl;
    showList(Lc);
    return 0;
}