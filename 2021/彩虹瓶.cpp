#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        bool leap = true;
        int num = 1;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            st.push(x);
            
            if (st.size() > m && x != num)
                leap = false;
            
            while (!st.empty())
            {
                
                if (st.top() == num) {
                    ++num;
                    st.pop();
                    
                }
                else
                    break;
            }
            
        }
        if (!st.empty())
            leap = false;
        if (leap)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
}