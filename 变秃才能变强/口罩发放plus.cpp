#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


struct people {
    string name;
    string num;
    bool body;
    string time;
    int day;
};

bool cmp(people a, people b) {
    return a.time < b.time;
}

void days(vector<people> &badbody, int &day, int &p) {
    int T, S;
    static vector<people> peoples;
    vector<people> temp;
    cin >> T >> S;
    for (int i = 0; i < T; ++i)
    {
        people peo;
        bool leap = true;
        cin >> peo.name >> peo.num >> peo.body >> peo.time;
        if (peo.num.length() != 18)
            leap = false;
        else
            for (auto r : peo.num)
                if (r < '0' || r > '9')
                {
                    leap = false;
                    break;
                }
        if (peo.body && leap)
        {
            bool leap = true;
            for (auto r : badbody)
                if (peo.name == r.name)
                {
                    leap = false;
                    break;
                }
            if (leap)
                badbody.push_back(peo);
        }
        if (leap)
        {
            temp.push_back(peo);
        }
    }
    if (!temp.empty())
        sort(temp.begin(), temp.end(), cmp);
    for (auto &r : temp)
    {
        bool leap = true;
        for (auto t : peoples)
        {
            if (r.name == t.name)
            {
                leap = false;
                if (t.day + p + 1 <= day)
                {
                    t.day = day;
                    cout << t.name << ' ' << t.num << endl;
                    --S;
                    break;
                }
            }
        }
        if (leap)
        {
            r.day = day;
            peoples.push_back(r);
            cout << r.name << ' ' << r.num << endl;
            --S;
        }
        if (!S)
            break;
    }
}

int main() {
    int D, P;
    cin >> D >> P;
    vector<people> badbody;
    for (int i = 1; i <= D; ++i)
        days(badbody, i, P);
    for (auto r : badbody)
        cout << r.name << ' ' << r.num << endl;
    return 0;
}