#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

bool Matching(string str)
{
    stack<char> st;
    map<char, char> m;
    m.insert({'(', ')'});
    m.insert({'[', ']'});
    m.insert({'{', '}'});

    try
    {

        for (string::iterator i = str.begin(); i != str.end(); i++)
        {
            if (m.find(*i) != m.end())
            {
                st.push(*i);
            }
            else
            {
                if (st.empty() && ((*i) == ')' || (*i) == ']' || (*i) == '}'))
                {
                    return false;
                }
                if (m[st.top()] == (*i))
                    st.pop();
            }
        }
    }
    catch (exception e)
    {
        return false;
    }
    if (st.empty())
        return true;
    return false;
}
int main()
{
    string str;
    getline(cin, str);
    if (Matching(str))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;}