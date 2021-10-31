#include <iostream>
#include <algorithm>
#include <vector>
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

Status CreateList_Up(Sqlist &L, int number)
{
    Sqnode *end = L;
    vector<ElemType> v;
    while (end->next != NULL)
        end = end->next;
    for (int i = 0; i < number; i++)
    {
        ElemType data;
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < number; i++)
    {
        Sqnode *node = new Sqnode;
        node->data = v[i];
        node->next = end->next;
        end->next = node;
        end = node;
    }

    return OK;
}

int cmp(ElemType a, ElemType b)
{
    return a < b;
}

void MergeList_Sq(Sqlist &a, Sqlist &b, Sqlist &c)
{
    Sqlist Ta = a, Tb = b, Tc = c;
    vector<ElemType> v;
    while ((Ta = Ta->next))
        v.push_back(Ta->data);
    while ((Tb = Tb->next))
        v.push_back(Tb->data);
    
    sort(v.begin(), v.end(), cmp);
    
    for (vector<ElemType>::iterator i = v.begin(); i != v.end(); i++)
    {
        Sqnode *t = new Sqnode;
        t->data = *i;
        t->next = Tc->next;
        Tc->next = t;
        Tc = Tc->next;
    }
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist La, Lb, Lc;                        //用来存储学生《数据结构》成绩
    InitList(La), InitList(Lb), InitList(Lc); //初始化线性表
    CreateList_Up(La, 3);                     //创建非递减链表
    cout << "Show La:" << endl;
    Show(La); //遍历线性表
    CreateList_Up(Lb, 4);
    cout << "Show Lb:" << endl;
    Show(Lb);
    MergeList_Sq(La, Lb, Lc); //将两个线性表元素合并到Lc(非递减)
    cout << "After Merging:" << endl;
    Show(Lc);

    return 0;
}