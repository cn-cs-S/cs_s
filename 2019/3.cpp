#include <iostream>
using namespace std;

int main()
{
    int sex, shen, ti;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sex >> shen >> ti;
        if (sex) {
            if (shen > 130)
                cout << "ni li hai!" << ' ';
            else if (shen < 130)
                cout << "duo chi yu!" << ' ';
            else
                cout << "wan mei!" << ' ';
            if (ti > 27)
                cout << "shao chi rou!" << endl;
            else if (ti < 27)
                cout << "duo chi rou!" << endl;
            else
                cout << "wan mei!" << endl;
        }
        else {
            if (shen > 129)
                cout << "ni li hai!" << ' ';
            else if (shen < 129)
                cout << "duo chi yu!" << ' ';
            else
                cout << "wan mei!" << ' ';
            if (ti > 25)
                cout << "shao chi rou!" << endl;
            else if (ti < 25)
                cout << "duo chi rou!" << endl;
            else
                cout << "wan mei!" << endl;
        }
    }
    
}