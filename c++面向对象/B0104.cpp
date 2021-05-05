#include<iostream>

bool isNum(int x, int num) {
    if (x % num == 0)
        return true;
    else
        return false;
}

int main() {
    for (int i = 1; i != 101; ++i) {
        if (isNum(i, 3))
            if (isNum(i, 5))
                std::cout << i << "*#" << std::endl;
            else
                std::cout << i << "*" << std::endl;
        else if (isNum(i, 5))
            std::cout << i << "#" << std::endl;
        else
            ;
    }

    
    return 0;
}