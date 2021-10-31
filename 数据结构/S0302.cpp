#include <iostream>
#include <stack>
#include <deque>
using namespace std;

struct SqStack
{
    deque<float> st;
};

void InitStack(SqStack sq)
{
    return;
}

void Push(SqStack &sq, float value)
{
    sq.st.push_back(value);
}

int GetTop(SqStack &sq)
{
    return sq.st.back();
}

void Pop(SqStack &sq)
{
    sq.st.pop_back();
}

bool StackEmpty(SqStack &sq)
{
    return sq.st.empty();
}

int StackLength(SqStack &sq)
{
    return sq.st.size();
}

void StackTraverse(SqStack &sq)
{
    for (deque<float>::iterator i = sq.st.begin(); i != sq.st.end(); ++i)
    {
        cout << *i << '\n';
    }
}

void ClearStack(SqStack &sq)
{
    sq.st.clear();
}

void DestroyStack(SqStack &sq)
{
    return;
}

int main()
{
    SqStack sint;
    InitStack(sint);

    int n;
    float s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        Push(sint, s);
    }
    if (!StackEmpty(sint))
    {
        cout << "There are " << StackLength(sint) << " numbers in the stack:" << endl;
        StackTraverse(sint); //从栈底到栈顶遍历
    }
    cout << "ClearStack()" << endl;
    ClearStack(sint);
    cout << StackLength(sint) << endl;
    DestroyStack(sint);
    return 0;
}