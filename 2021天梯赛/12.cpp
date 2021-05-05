#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct st
{
    string str;
    int num = 0;
};

bool cmp(st s1, st s2) {
    if (s1.num == s2.num)
        return s1.str < s2.str;
    return s1.num > s2.num;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<st> v;
    getchar();
    for (int i = 0; i < n; i++)
    {
        st s;
        getline(cin, s.str);
        bool leap = true;
        for (auto &r: v) {
            if (r.str == s.str) {
                r.num++;
                leap = false;
                break;
            }
            
        }
        if (leap) {
            s.num = 1;
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (auto r: v) {
        cout << r.num << ' ' << r.str << endl;
    }
}