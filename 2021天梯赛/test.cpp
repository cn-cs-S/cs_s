#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(NULL));
    int n = rand() % 50 + 1;
    ofstream is;
    is.open("test.txt", ios::trunc);
    is << n << endl;
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10 + 1;
        is << num << ' ';
    }
    is.close();
}