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

int Max(LinkList &l)
{
    LinkNode *t = l;
    int max = t->next->data;
    while (t = t->next)
    {
        if (max < t->data)
            max = t->data;
    }
    return max;
}

int main()
{
    LinkList Lscore;
    InitList(Lscore);        //初始化单链表
    showList(Lscore);        //单链表遍历
    CreateList_R(Lscore, 5); //后插法创建单链表
    cout << Max(Lscore) << endl;
    return 0;
}