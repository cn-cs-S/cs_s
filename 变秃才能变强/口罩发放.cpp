#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct people {
    string name;
    string num;
    int body;
    string time;
    int day = -30;
};

bool cmp(people a, people b) {
    return a.time < b.time;
}

int main(){
    int D, P;
    int T, S;
    cin >> D >> P;
    int number = 0;
    people peo[1000];
    people mask[10000];
    int day = 0;
    int masknum = 0;
    for (int i = 0; i < D; i++)
    {
        ++day;
        cin >> T >> S;
        people days[1000];
        for (int t = 0; t < T; t++)
        {
            cin >> days[t].name >> days[t].num >> days[t].body >> days[t].time;
            if (days[t].num.length() != 18)
            {
                --t;
                --T;
            }
        }
        sort(days, days + T, cmp);
        for (int t = 0; t < T; t++)
        {
            bool leap = 1;
            for (int j = 0; j < number; j++)
            {
                if (days[t].num == peo[j].num)
                {
                    if (days[t].body)
                    {
                        peo[j].body = days[t].body;
                    }
                    if (peo[j].day + P + 1 <= day)
                    {
                        if (S)
                        {
                            peo[j].day = day;
                            mask[masknum++] = peo[j];
                            --S;
                        }
                    }
                    leap = 0;
                    break;
                }
            }
            if (leap)
            {
                peo[number++] = days[t];
                if (S)
                {
                    peo[number-1].day = day;
                    mask[masknum++] = peo[number-1];
                    --S;
                }
            }
        }
    }
    for (int i = 0; i < masknum; i++)
    {
        cout << mask[i].name << ' ' << mask[i].num << endl;
    }
    for (int i = 0; i < number; i++)
    {
        if (peo[i].body)
        {
            cout << peo[i].name << ' ' << peo[i].num << endl;
        }
    }
    return 0;
}