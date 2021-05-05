#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> stu;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        stu.push_back(x);
    }
    sort(stu.begin(), stu.end());
    int low = 1, up = 1;
    for (int i = 0; i < n; i++)
    {
        if (stu[i+1] == stu[i])
            ++low;
        else
            break;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (stu[i - 1] == stu[i])
            ++up;
        else
            break;
    }
    cout << stu[0] << ' ' << low << endl;
    cout << stu[n-1] << ' ' << up;
}