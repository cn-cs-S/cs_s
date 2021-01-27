#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double midu, shuxing, bizhi;
    cin >> midu >> shuxing >> bizhi;
    if (shuxing)
    {
        shuxing = 1.26;
    }
    else
    {
        shuxing = 2.455;
    }
    printf("%.2lf ", midu * shuxing);
    if (midu * shuxing / bizhi < 1)
    {
        cout << "^_^";
    }
    else
    {
        cout << "T_T";
    }
    return 0;
}
