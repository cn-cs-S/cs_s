#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct LinkStack
{
    stack<string> st;
};

void InitStack(LinkStack sq)
{
    return;
}

void Push(LinkStack &sq, string value)
{
    sq.st.push(value);
}

string GetTop(LinkStack &sq)
{
    return sq.st.top();
}

void Pop(LinkStack &sq)
{
    sq.st.pop();
}

bool StackEmpty(LinkStack &sq)
{
    return sq.st.empty();
}

int main()
{
    LinkStack Ls;
    InitStack(Ls); //初始化链栈
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        Push(Ls, s); //入栈
    }

    while (!StackEmpty(Ls))
    {
        cout << GetTop(Ls) << endl; //取栈顶元素
        Pop(Ls);                    //出栈
    }
}