#include <iostream>
using namespace std;

struct Base
{
public:
    void print()
    {
        cout << "x=" << this->x << endl;
    }
    Base()
    {
        cout << "Base()..." << endl;
    }

protected:
    int x;
};

struct Base1 : virtual public Base
{
    Base1()
    {
        cout << "Base1()..." << endl;
    }
    Base1(int x)
    {
        this->x = x;
        cout << "Base1()..." << endl;
    }
    void print()
    {
        cout << "x=" << this->x << endl;
    }
};

struct Base2 : virtual public Base
{
    Base2()
    {
        cout << "Base2()..." << endl;
    }
    Base2(int x)
    {
        this->x = x;
        cout << "Base2()..." << endl;
    }
    void print()
    {
        cout << "x=" << this->x << endl;
    }
};

struct Derive : public Base1, public Base2
{
    Derive(int x)
    {
        this->x = x;
        cout << "Derive()..." << endl;
    }
    void print()
    {
        cout << "x=" << this->x << endl;
    }
};

int main()
{
    Base1 b1(1);
    b1.print();
    Base2 b2(2);
    b2.print();
    Derive d(3);
    d.print();
    return 0;
}