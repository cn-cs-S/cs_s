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

struct before_compare
{
    bool operator()(LinkNode *a, LinkNode *b) const
    {
        return a->data > b->data;
    }
};

struct after_compare
{
    bool operator()(LinkNode *a, LinkNode *b) const
    {
        return a->data < b->data;
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

    multiset<LinkNode *, before_compare> s;
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

    for (multiset<LinkNode *>::iterator i = s.begin(); i != s.end(); ++i)
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
    multiset<LinkNode *, after_compare> all;
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

    for (multiset<LinkNode *>::iterator i = all.begin(); i != all.end(); ++i)
    {
        (*i)->next = c->next;
        c->next = *i;
    }
}

int main()
{
    LinkList La, Lb, Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);         //初始化带头结点的单链表
    CreateList_Up(La, 3); //创建非递减单链表
    cout << "Show La:" << endl;
    showList(La);         //单链表遍历
    CreateList_Up(Lb, 4); //创建非递减单链表
    cout << "Show Lb:" << endl;
    showList(Lb); //单链表遍历

    MergeList(La, Lb, Lc); //合并链表为非递增单链表Lc
    cout << "Show Lc:" << endl;
    showList(Lc); //单链表遍历
    return 0;
}