#include <iostream>
using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    int wh[201][201]; //家为0, 网红点为1~N

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> wh[x][y];
        wh[y][x] = wh[x][y]; //双向通道
    }

    int K;
    unsigned long long min = 1e9 + 1;//最大为1e9, 所以定义为1e9+1
    int xuhao = 0;  //序号
    int sum = 0;    //数量

    cin >> K;

    for (int i = 1; i < K + 1; ++i)
    {
        int gonglue;
        int begin, next;
        int leap = 1; //标志变量, 用于判断攻略是否满足条件
        unsigned long long money = 0;

        cin >> gonglue;
        cin >> begin;

        if (gonglue != N || !wh[0][begin])  //如果攻略给出的地点数和网红点数不相等, 就不符合条件
            leap = 0;

        money += wh[0][begin]; 

        int *number = new int[gonglue]();

        int y = 1;

        number[0] = begin;

        for (int j = 1; j < gonglue; ++j)   
        {
            cin >> next;

            for (int t = 0; t < y && leap; ++t)
                if (next == number[t])  //是否重复
                    leap = 0;

            number[y++] = next;

            if (wh[begin][next] == 0 && leap)   //看看能不能去下一个地点
                leap = 0;                       //p.s. 这题好像给的都是可以去下一个地点的

            money += wh[begin][next];

            begin = next;
        }

        money += wh[begin][0];

        delete[] number;

        if (!wh[begin][0] && leap)      //看看能不能回家
            leap = 0;

        if (leap)
        {
            if (money < min)
            {
                xuhao = i;
                min = money;
            }

            ++sum;
        }
    }

    cout << sum << endl;
    cout << xuhao << ' ' << min;

    return 0;
}