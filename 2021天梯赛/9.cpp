#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    stack<char> st;
    vector<queue<char> > v;
    getchar();
    for (int i = 0; i < n; i++)
    {
        queue<char> q;
        for (int t = 0; t < m; t++)
        {
            char c = getchar();
            q.push(c);
            
        }
        v.push_back(q);
        getchar();
    }
    do {
        int n;
        cin >> n;
        
        if (n == -1)
            break;
        if (n != 0) {
            if (st.size() == s)
            {
                cout << st.top();
                st.pop();
            }
            if (v[n-1].empty())
                continue;
            st.push(v[n-1].front());
            v[n-1].pop();
            
        }
        else {
            if (st.empty())
                continue;
            cout << st.top();
            st.pop();
        }
        
        
    }while(1);
}