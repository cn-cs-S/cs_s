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

int main()
{
    LinkList Lname;
    InitList(Lname);        //初始化单链表
    CreateList_R(Lname, 3); //后插法创建单链表
    showList(Lname);        //单链表遍历
    string s;
    int i;
    cin >> i;
    if (GetElem(Lname, i, s) == OK)
        cout << s << endl;
    else
        cout << "Error!" << endl;
    return 0;
}