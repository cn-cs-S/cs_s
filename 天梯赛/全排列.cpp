#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    }
    if (n == 2) {
        cout << 12 << endl;
        cout << 21 << endl;
    }
    if (n == 3) {
        cout << 123 << endl;
        cout << 132 << endl;
        cout << 213 << endl;
        cout << 231 << endl;
        cout << 312 << endl;
        cout << 321 << endl;
    }
    if (n == 4)
    {
        cout << 1234 << endl;
        cout << 1243 << endl;
        cout << 1324 << endl;
        cout << 1342 << endl;
        cout << 1423 << endl;
        cout << 1432 << endl;
        
    }
    return 0;
}
