#include<iostream>

inline int product(int x, int y, int z){
    std::cout << x << '*' << y << '*' << z << '=' << x * y * z;
    return x * y * z;
}

int main(){
    int x, y, z;
    std::cin >> x >> y >> z;
    product(x, y, z);
    return 0;
}