#include<iostream>
#include<vector>

int main(){
    std::vector<int> fib;
    int first = 1, second = 1;
    fib.push_back(first);
    fib.push_back(second);
    int n = 0;
    std::cin >> n;
    while (n < 2)
    {
        std::cout << "Please reinput n(n>=2):" <<std::endl;
        std::cin >> n;
    }
    for (int i = 2; i < n; i++)
    {
        second = first + second;
        first = second - first;
        fib.push_back(second);
    }
    for (auto r : fib)
        std::cout << r << std::endl;
    return 0;
}