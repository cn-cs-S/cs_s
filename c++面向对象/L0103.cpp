#include<iostream>
using namespace std;

double max( double x ,double y )
{
    if( x >= y )
        return x ;
    else
        return y ;
}

int main()
{
    double max(double x, double y);
    double a,b,m;
    cin>>a>>b;
    m=max(a,b);
    cout<<"max="<<m<<endl;
    return 0;
} 