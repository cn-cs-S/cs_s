#include<iostream>
#include<iomanip>
#include<cmath>

class complex {
public:
    complex() : real(0), imag(0) {};
    void setReal() {
        std::cin >> real;
        this->real = real;
    }
    void setImag() {
        std::cin >> imag;
        this->imag = imag;
    }
    double mod() {
        return std::sqrt(real * real + imag * imag);
    }
private:
    double real;
    double imag;
};

int main(){
    complex cpx;
    cpx.setReal();
    cpx.setImag();
    std::cout << cpx.mod();
    return 0;
}