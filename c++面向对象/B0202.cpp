#include<iostream>
#include<cmath>

bool isPrime(int &x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main(){
    int n;
    std::cin >> n;
    while (n < 2)
    {
        std::cout << "Please reinput n(n>=2):";
        std::cin >> n;
    }
    if (isPrime(n))
        std::cout << n << " is a prime number.";
    else
        std::cout << n << " is not a prime number.";
    return 0;
}