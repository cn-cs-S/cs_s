#include <iostream>

int main()
{
    int n;
    double aver = 0;
    std::cin >> n;
    double *p = new double[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        aver += p[i];
    }

    aver /= n;
    std::cout << "aver=" << aver;

    delete p;
}