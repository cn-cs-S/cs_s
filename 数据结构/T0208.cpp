#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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

struct compare
{
    bool operator()(LinkNode *a, LinkNode *b) const
    {
        return a->data > b->data;
    }
};

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

int cmp(LinkNode *a, LinkNode *b)
{
    return a->data > b->data;
}

Status CreateList_Up(LinkList &L, int number)
{

    set<LinkNode *, compare> s;
    for (int i = 0; i < number; i++)
    {
        LinkNode *t = new LinkNode;
        cin >> t->data;
        s.insert(t);
    }

    // for (auto &r : s)
    // {
    //     r->next = L->next;
    //     L->next = r;
    // }

    for (set<LinkNode *>::iterator i = s.begin(); i != s.end(); ++i)
    {
        (*i)->next = L->next;
        L->next = *i;
    }

    // vector<LinkNode *> vec;
    // for (int i = 0; i < number; i++)
    // {
    //     LinkNode *t = new LinkNode;
    //     cin >> t->data;
    //     vec.push_back(t);
    // }
    // sort(vec.begin(), vec.end(), cmp);
    // for (vector<LinkNode *>::iterator i = vec.begin(); i != vec.end(); ++i)
    // {
    //     (*i)->next = L->next;
    //     L->next = *i;
    // }
    return OK;
}

Status GetElem(const LinkList &L, int index, ElemType &value)
{
    if (!L->next)
        return ERROR;
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        if (++i == index)
            break;
        p = p->next;
    }
    if (i != index)
        return ERROR;
    value = p->data;
    return OK;
}

Status LocateElem(const LinkList &L, const ElemType &value)
{
    if (!L->next)
        return ERROR;
    LinkList p = L->next;
    while (p)
    {
        if (p->data == value)
            return OK;
        p = p->next;
    }
    return ERROR;
}

Status ListInsert(LinkList &L, int index, const ElemType &value)
{
    if (!L->next)
        return ERROR;
    int i = 0;
    LinkList p = L;
    while (p)
    {
        if (++i == index)
            break;
        p = p->next;
    }
    if (i != index)
        return ERROR;
    LinkNode *node = new LinkNode;
    node->data = value;
    node->next = p->next;
    p->next = node;
    return OK;
}

Status ListDelete(LinkList &L, int index)
{
    if (!L->next)
        return ERROR;
    int i = 0;
    LinkList p = L;
    while (p)
    {
        if (++i == index)
            break;
        p = p->next;
    }
    if (i != index)
        return ERROR;
    LinkNode *t = p->next;
    p->next = p->next->next;
    delete t;
    return OK;
}

void MergeList(LinkList a, LinkList b, LinkList c)
{
    LinkList ta = a, tb = b;
    set<LinkNode *, compare> all;
    while (ta = ta->next)
    {
        LinkNode *t = new LinkNode;
        t->data = ta->data;
        all.insert(t);
    }

    while (tb = tb->next)
    {
        LinkNode *t = new LinkNode;
        t->data = tb->data;
        all.insert(t);
    }

    for (set<LinkNode *>::iterator i = all.begin(); i != all.end(); ++i)
    {
        (*i)->next = c->next;
        c->next = *i;
    }
}

void DeleteMinMax(LinkList &l, int min, int max)
{
    LinkNode *t = l;
    while (t->next)
    {
        if (t->next->data > min && t->next->data < max)
        {
            LinkNode *temp = t->next;
            t->next = temp->next;
            delete temp;
        }
        else
            t = t->next;
    }
}

int main()
{
    LinkList La;
    InitList(La);         //初始化带头结点的单链表(存储int类型数据)
    CreateList_Up(La, 6); //创建递增单链表（去掉重复数据）
    cout << "Show La:" << endl;
    showList(La); //单链表遍历
    int mink, maxk;
    cin >> mink >> maxk;
    DeleteMinMax(La, mink, maxk); //链表中去掉(mink,maxk)区间的元素
    cout << "After deleting (" << mink << "," << maxk << "):" << endl;
    showList(La); //单链表遍历
    return 0;
}