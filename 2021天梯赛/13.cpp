#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ve;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        ve.push_back(v);
    }
    int now = 1;
    int dang[n];
    for (int i = 0; i < m; i++)
    {
        int how, where;
        cin >> how >> where;
        
        if (how == 0) {
            now = ve[now-1][where-1];
            
        }
        else if (how == 1) {
            dang[where-1] = now;
            cout << now << endl;
        }
        else {
            now = dang[where-1];
        }
        
    }
    cout << now;
}