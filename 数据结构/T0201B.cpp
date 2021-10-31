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
    void MergeLink(SingleList<T>);

private:
    multiset<T> s;
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

    for (typename multiset<T>::iterator i = s.begin(); i != s.end(); ++i)
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
void SingleList<T>::MergeLink(SingleList<T> other)
{
    this->s.insert(other.s.begin(), other.s.end());
}

int main()
{
    SingleList<int> sa, sb;
    sa.show(); //遍历链表
    int s;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        sa.Insert(s);
    }          //构造可有重复元素的非递减单链表sa
    sa.show(); //遍历链表
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        sb.Insert(s);
    } //构造可有重复元素的非递减单链表sa
    sb.show();
    sa.MergeLink(sb); //合并两个链表
    sa.show();
    return 0;
}