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

void CreateList(Sqlist &l, int num)
{
    for (int i = 0; i < num; i++)
    {
        cin >> l.elem[i];
        l.length++;
    }
}

void Show(Sqlist &l)
{
    if (!l.length)
        cout << "Empty!" << '\n';
    for (int i = 0; i < l.length; i++)
    {
        cout << l.elem[i] << '\n';
    }
}

void DeleteItem(Sqlist &l, int value)
{
    int i, k;
    for (i = 0, k = 0; i < l.length; i++)
    {
        if (l.elem[i] != value)
        {
            l.elem[k++] = l.elem[i];
        }
    }
    l.length -= i - k;
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore;         //用来存储学生《数据结构》成绩
    InitList(Lscore);      //初始化线性表
    CreateList(Lscore, 5); //创建线性表
    Show(Lscore);          //遍历线性表
    cout << "Please input the item you want to delete:" << endl;
    int item;
    cin >> item;
    DeleteItem(Lscore, item); //删除所有值为item的元素
    cout << "After deleting:" << endl;
    Show(Lscore); //遍历线性表

    return 0;
}
