#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0, min = 999999, up = 0, low = 0;
    for (int i = 0; i < n; i++)
    {
        int stu;
        cin >> stu;
        if (stu > max) {
            max = stu;
            up = 1;
        }
        else if (stu == max) {
            ++up;
        }
        if (stu < min)
        {
            min = stu;
            low = 1;
        }
        else if (stu == min)
        {
            ++low;
        }
    }
    cout << min << ' ' << low << endl;
    cout << max << ' ' << up;
}