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

int main()
{
    LinkList Lname;
    InitList(Lname);        //初始化单链表
    CreateList_R(Lname, 3); //后插法创建单链表
    showList(Lname);        //单链表遍历
    int i;
    string s;
    cin >> i >> s;
    if (ListInsert(Lname, i, s) != NULL)
        cout << "Insert success!" << endl;
    else
        cout << "Error!" << endl;
    showList(Lname); //单链表遍历
    return 0;
}