#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

struct luoji {
    array<array<int, 500+1>, 500+1> vexs;
    bool ziqia = 1;
    int vexnum;
    int arcnum;
};

int bianli(luoji &lj, int &begin, int &end) {
    static int sum = 0;
    int leap = 1;
    for (int i = 1; i <= lj.vexnum; i++)
    {
        if (lj.vexs[begin][i])
        {
            leap = 0;
            if (i == end)
            {
                ++sum;
                continue;
            }
            else
                bianli(lj, i, end);
        }
    }
    if (leap)
    {
        if (begin != end)
            lj.ziqia = 0;
    }
    return sum;
}

int main() {
    luoji lj;
    cin >> lj.vexnum >> lj.arcnum;
    for (int i = 1; i <= lj.vexnum; i++)
        for (int t = 1; t <= lj.vexnum; t++)
            lj.vexs[i][t] = 0;
    for (int i = 0; i < lj.arcnum; i++)
    {
        int x, y;
        cin >> x >> y;
        lj.vexs[x][y] = 1;
    }
    int begin, end;
    cin >> begin >> end;

    int sum = bianli(lj, begin, end);
    cout << sum << ' ';

    for (int i = 1; i <= lj.vexnum; i++)
    {
        if (lj.vexs[end][i])
        {
            lj.ziqia = 0;
            break;
        }
    }
    if (lj.ziqia)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}