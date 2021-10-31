#include <iostream>
#include <iterator>
#include <set>
using namespace std;

template <class T>
class SingleList
{
public:
    void show();
    void Insert(T);

    set<T> s;
};

template <class T>
void SingleList<T>::show()
{
    if (s.empty())
    {
        cout << "Empty!" << '\n';
        return;
    }

    printf("There are %d scores in the Linklist:\n", s.size());

    for (typename set<T>::iterator i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << '\n';
    }
    cout << '\n';
}

template <class T>
void SingleList<T>::Insert(T data)
{
    s.insert(data);
}

template <class T>
void MergeLink(SingleList<T> &a, SingleList<T> &b)
{
    a.s.insert(b.s.begin(), b.s.end());
}

int main()
{
    SingleList<int> sa, sb; //创建有头结点的单链表
    sa.show();              //遍历链表
    int s;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        sa.Insert(s);
    }          //构造无重复元素的递增单链表sa
    sa.show(); //遍历链表
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        sb.Insert(s);
    } //构造无重复元素的递增单链表sa
    sb.show();
    MergeLink(sa, sb); //合并两个链表，去掉重复元素
    sa.show();
    return 0;
}