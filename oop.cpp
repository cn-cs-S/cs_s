#include <iostream>
class A {
  public:
    void f();
    virtual void ff() = 0;
};

class B: public A {
  public:
    void ff() override;
};

void A::f() {
    ff();
}

void A::ff(){
    std::cout << 'A';
}

void B::ff() {
    std::cout << 'B';
}

int main() {
    A* c = new B;
    c->f();
}