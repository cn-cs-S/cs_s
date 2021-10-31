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

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore;    //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表
    int i;
    for (i = 1; i <= 5; i++)
    {
        ListInsert(Lscore, i, 80 + i); //线性表中添加数据
    }

    int s1, s2;      //
    cin >> s1 >> s2; //输入两个成绩
    ListInsert(Lscore, 3, s1);
    ListInsert(Lscore, 5, s2);
    int len = Lscore.length;
    int s;
    for (i = 1; i <= len; i++)
    {
        GetElem(Lscore, i, s); //获取线性表中数据
        cout << s << endl;
    }
    return 0;
}