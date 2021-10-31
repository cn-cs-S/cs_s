#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define Status int
#define ElemType int
using namespace std;

struct Sqlist
{
    ElemType *elem;
    int length;
};

Status InitList(Sqlist &L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status ListInsert(Sqlist &L, int index, int value)
{
    if (!L.elem)
        exit(OVERFLOW);
    if (index >= MAXSIZE)
        exit(ERROR);
    for (int i = L.length; i >= index; --i)
    {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[index] = value;
    L.length++;
    return OK;
}

Status GetElem(const Sqlist &L, int index, int &value)
{
    if (!L.elem)
        exit(OVERFLOW);
    if (index >= MAXSIZE)
        exit(ERROR);
    value = L.elem[index];
    return OK;
}

Status LocateElem(const Sqlist &L, int value)
{
    for (int i = 1; i <= L.length; i++)
        if (value == L.elem[i])
            return i;
    return 0;
}

Status ListDelete(Sqlist &L, int index)
{
    if (index > L.length)
        return ERROR;
    for (int i = index; i < L.length; i++)
        L.elem[i] = L.elem[i + 1];
    L.length--;
    return OK;
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore;    //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表
    int i, s;
    for (i = 1; i <= 3; i++) //输入3个学生成绩，添加到线性表中
    {
        cin >> s;
        ListInsert(Lscore, i, s); //线性表中添加数据
    }

    int loc;
    cin >> loc; //输入要删除的位置
    if (ListDelete(Lscore, loc) == OK)
        cout << "delete success!" << endl;
    else
        cout << "Error!" << endl;

    for (i = 1; i <= Lscore.length; i++) //遍历线性表
    {
        int ele;
        GetElem(Lscore, i, ele);
        cout << ele << endl;
    }

    return 0;
}