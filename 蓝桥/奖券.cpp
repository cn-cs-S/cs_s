#include<iostream>
int main(){
    int sum=90000;
    for (int i = 10000; i < 100000; )
    {
        if (i/10000-4==0)
        {
            sum-=10000;
            i+=10000;
            continue;
        }
        if (i/1000-4==0)
        {
            sum-=1000;
            i+=1000;
            continue;
        }
        if (i/100-4==0)
        {
            sum-=100;
            i+=100;
            continue;
        }
        if (i/10-4==0)
        {
            sum-=10;
            i+=10;
            continue;
        }
        if (i-4==0)
        {
            sum-=1;
        }
        i++;
    }
    std::cout<<sum<<std::endl;
    return 0;
}