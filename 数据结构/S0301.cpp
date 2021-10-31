#include <iostream>
#include <stack>
using namespace std;

struct SqStack
{
    stack<int> st;
};

void InitStack(SqStack sq)
{
    return;
}

void Push(SqStack &sq, int value)
{
    sq.st.push(value);
}

int GetTop(SqStack &sq)
{
    return sq.st.top();
}

void Pop(SqStack &sq)
{
    sq.st.pop();
}


int main()
{
    SqStack sint;
    InitStack(sint);

    int s;
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        Push(sint, s);
    }

    for (int i = 0; i < 4; i++)
    {
        int e = GetTop(sint);
        Pop(sint);
        cout << e << endl;
    }
    return 0;
}