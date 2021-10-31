/**
 * 此为顺序表的各种操作
 * 仅供本人参考使用
 * 语言为c/c++
 * 注释比代码长系列
*/

/**
 * 顺序表和链表一样是动态分配空间
 * 这和之前使用的数组是不同的
 * 显而易见,应该用结构体表示
*/

#include<iostream>
#define ElemType int
#define MAX_NUM 100
using namespace std;

typedef struct{
    ElemType *elem;
    int length;
}Sqlist;

bool creatList(Sqlist &list) {
    list.elem = new ElemType[MAX_NUM];
    if (!list.elem)
        return false;
    list.length = 0;
    return true;
}

void destroyList(Sqlist &list) {
    if (list.elem)
        delete [] list.elem;
}

void clearList(Sqlist &list) {
    list.length = 0;
}

bool isEmpty(Sqlist list) {
    return list.length;
}

int getLength(Sqlist list) {
    return list.length;
}

bool getElem(Sqlist list, int i, ElemType &e) {
    if (i < 1 || i > list.length)
        return false;
    e = list.elem[i-1];
    return true;
}

int findElem(Sqlist list, ElemType e) {
    for (int i = 0; i < list.length; i++)
        if (list.elem[i] == e)
            return i+1; 
    return 0;
}

bool listInsert(Sqlist &list, int i, ElemType e) {
    if (i < 1 || i > list.length)
        return false;
    for (int t = list.length - 1; t >= i-1; t--)
        list.elem[t+1] = list.elem[t];
    list.elem[i-1] = e;
    list.length++;
    return true;
}

bool listDelete(Sqlist &list, int i) {
    if (i < 1 || i > list.length)
        return false;
    for (int t = i - 1; t < list.length-1; t++)
        list.elem[t] = list.elem[t+1];
    list.length--;
    return true;
}

int main(){
    return 0;
}