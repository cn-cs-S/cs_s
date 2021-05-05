#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    vector<string> stu;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stu.push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << stu[q-1] << endl;
    }
    
    return 0;
}
