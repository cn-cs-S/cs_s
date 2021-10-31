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

int Exchange(DuLinkList &l, int index)
{
    if (index <= 1)
        return !OK;
    DuLinkNode *t = l->next;
    int i = 0;
    while (++i && t)
    {
        if (i > index)
            break;
        if (i == index)
        {
            t->pre->pre->next = t;
            t->pre->next = t->next;
            if (t->next)
                t->next->pre = t->pre;
            t->next = t->pre;
            t->pre = t->pre->pre;
            t->pre->pre = t;
            return OK;
        }
        t = t->next;
    }
    return !OK;
}

int main()
{
    DuLinkList L;
    InitDuLNode(L);    //初始化双向链表
    CreateDuL_H(L, 4); //后插法创建双向链表
    show(L);           //遍历双向链表
    int i;
    cout << "Please input the location(i>1) you want to exchange:" << endl;
    cin >> i;
    if (Exchange(L, i) == OK)
        cout << "Exchange success!" << endl;
    else
        cout << "Exchange Error!" << endl;
    show(L);
    return 0;
}