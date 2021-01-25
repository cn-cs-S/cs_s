
#include<iostream>
#include<algorithm>
using namespace std;

class system {
    public:
    void login();
    void interface();
    void enter();
    void showAllStudent();
    void addStudent();
    void deleteStudent();
    void findStudent();
};

class Student : public system {

};

class Teacher : public system {

};

void system::login() {
    printf("请输入学号和密码");
    
}

void system::interface() {

}