#include<iostream>
#include<cmath>

int main() {
    int a, n;
    unsigned result = 0;
    std::cin >> a >> n;
    for (int i = 0; i < n; i++)
        result += a * pow(10, i) * (n - i);
    std::cout << result;
    return 0;
}