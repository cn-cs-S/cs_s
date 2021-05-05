#include<iostream>
using namespace std;

int main() {
    char a;
    a = getchar();
    if (a >= 'a' && a <= 'z') 
        a += 'A' - 'a';
    else
        a -= 'A' - 'a';
    cout << a ;
}