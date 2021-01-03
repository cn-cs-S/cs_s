#include<iostream>
using namespace std;
int main(){

   // cout<<2015-1225<<endl;
   // cout<<10*10+27*27-11-28<<endl;
    for (int i = 1; i < 47; i++)
    {
        bool leap=false;
        for (int t = i+2; t < 49; t++)
        {
            if (i*i+t*t-i-t-2==790)
            {
                cout<<i<<endl;
                leap=true;
                continue;;
            }
            
        }
        if (leap)
        {
            continue;
        }
        
    }
    return 0;
}