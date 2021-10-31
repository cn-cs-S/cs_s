#include <iostream>
#include <string>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define Status int
#define ElemType int
using namespace std;

typedef struct Sqnode
{
    Sqnode *next;
    ElemType data;
} * Sqlist;

void InitList(Sqlist &L)
{
    L = new Sqnode;
    L->next = NULL;
}

void Show(const Sqlist &L)
{
    if (!L->next)
    {
        cout << "empty!" << '\n';
        return;
    }
    Sqlist p = L->next;
    int i = 1;
    while (p)
    {
        cout << p->data << '\n';
        p = p->next;
    }
}

Status CreateList(Sqlist &L, int number)
{
    Sqnode *end = L;
    while (end->next != NULL)
        end = end->next;
    for (int i = 0; i < number; i++)
    {
        Sqnode *node = new Sqnode;
        cin >> node->data;
        node->next = end->next;
        end->next = node;
        end = node;
    }

    return OK;
}


void MergeList(Sqlist &a, Sqlist &b)
{
    Sqlist Ta = a;
    Sqlist Tb = b->next;
    while (Tb)
    {
        do
        {
            Ta = Ta->next;
            if (Ta->data == Tb->data)
            {
                Ta = a;
                break;
            }
        }while(Ta->next);
        if (Ta != a)
        {
            Sqlist t = new Sqnode;
            t->data = Tb->data;
            t->next = Ta->next;
            Ta->next = t;
        }
        Ta = a;
        Tb = Tb->next;
    }
    
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist La, Lb;              //用来存储学生《数据结构》成绩
    InitList(La), InitList(Lb); //初始化线性表
    CreateList(La, 3);          //创建链表
    cout << "Show La:" << endl;
    Show(La); //遍历线性表
    CreateList(Lb, 4);
    cout << "Show Lb:" << endl;
    Show(Lb);
    MergeList(La, Lb); //将两个线性表元素合并到La
    cout << "After Merging:" << endl;
    Show(La);

    return 0;
}