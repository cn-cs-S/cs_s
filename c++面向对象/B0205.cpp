#include<iostream>
#include<iomanip>

double function(int n) {
    double first = 1, second = 2;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += second / first;
        second = first + second;
        first = second - first;
    }
    return sum;
}

int main(){
    int n;
    std::cin >> n;
    std::printf("%.2lf",function(n));
    return 0;
}