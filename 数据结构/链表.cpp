/**
 * 此为链表的各种操作
 * 仅供本人参考使用
 * 语言为c/c++
 * 注释比代码长系列
*/

#include<iostream>
using namespace std;

struct ElemType {
    int x;
    char y;
};

struct LNode {
    ElemType data;
    LNode* next;
};
using LinkList = LNode*;

bool iniList(LinkList &list) {
    list = new LNode;
    list->next = nullptr;
    return true;
}

bool IsEmpty(LinkList list) {
    if (list->next)
        return false;
    return true;
}

bool destroyList(LinkList &list) {
    LNode *p = nullptr;
    while (list)
    {
        p = list;
        list = list->next;
        delete p;
    }
    return true;
}

bool clearList(LinkList &list) {
    
}

int main(){
    return 0;
}