#include <iostream>
#include <string>
using namespace std;
class score
{
public:
    score(float c, float e, float m)
    {
        Computer = c;
        English = e;
        Math = m;
    }
    void show()
    {
        cout << "Computer:" << Computer << endl;
        cout << "English:" << English << endl;
        cout << "Math:" << Math << endl;
    }

private:
    float Computer;
    float English;
    float Math;
};

class student
{
public:
    student(string name1, string stu_no1, float s1, float s2, float s3) : s(s1, s2, s3)
    {
        name = name1;
        stu_no = stu_no1;
    }
    void show()
    {
        cout << endl
             << "Name:" << name << endl;
        cout << "No:" << stu_no << endl;
        s.show();
    }

private:
    string name;
    string stu_no;
    score s;
};

int main()
{
    student stu1("Li Xiaoming", "990201", 90, 80, 70);
    stu1.show();
    student stu2("Zhang Yongsheng", "08150202", 89, 88, 87);
    stu2.show();
    return 0;
}
