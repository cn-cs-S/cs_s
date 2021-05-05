#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void find(vector<vector<int> >& v , int &sum, int &n, int &now) {
    
    for (int i = 0; i < n; i++)
    {
        if (v[now][i] != 0)
        
            find(v, sum, n, i);
        
    }
    sum++;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > ve;
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 0) {
            q.push_back(i);
        }
        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        ve.push_back(v);
    }
    int num = 0;
    for (auto r: q) {
        int sum = 0;
        find(ve, sum, n, r);
        if (sum > num)
            num = sum;
    }
    cout << num;
}