#include <iostream>
using namespace std;
#define OK 1
#define DuLinkList DuLinkNode *
#define nullptr 0

struct DuLinkNode
{
    int data;
    DuLinkNode *pre;
    DuLinkNode *next;
};

void InitDuLNode(DuLinkList &L)
{
    L = new DuLinkNode;
    L->pre = nullptr;
    L->next = nullptr;
    L->data = 0;
}

void CreateDuL_H(DuLinkList &L, int n)
{
    while (n--)
    {
        DuLinkList d = new DuLinkNode;
        cin >> d->data;
        d->next = L->next;
        L->next = d;
        if (d->next)
            d->next->pre = d;
        d->pre = L;
    }
}

void show(DuLinkList &L)
{
    int n = 0;
    DuLinkList p = L->next;
    while (p)
    {
        cout << ++n << ':' << p->data << '\n';
        p = p->next;
    }
}

int ListDelete_DuL(DuLinkList &L, int i)
{
    DuLinkList p = L->next;
    while (p && --i)
        p = p->next;
    if (!p)
        return -1;
    if (p->pre)
        p->pre->next = p->next;
    if (p->next)
        p->next->pre = p->pre;
    delete p;
    return OK;
}

int ListInsert_DuL(DuLinkList &L, int index, int value)
{
    int i = 0;
    DuLinkList p = L->next;
    while (p)
    {
        if (++i == index)
            break;
        p = p->next;
    }
    if (i != index)
        return !OK;
    DuLinkNode *t = new DuLinkNode;
    t->data = value;
    p->pre->next = t;
    t->pre = p->pre;
    t->next = p;
    p->pre = t;
    return OK;
}

int main()
{
    DuLinkList L;
    InitDuLNode(L);    //初始化双向链表
    CreateDuL_H(L, 4); //后插法创建双向链表
    show(L);           //遍历双向链表
    int i, s;
    cout << "Please input the location and number you want to insert:" << endl;
    cin >> i >> s;
    if (ListInsert_DuL(L, i, s) == OK)
        cout << "Insert success!" << endl;
    else
        cout << "Insert Error!" << endl;
    show(L);
    return 0;
}