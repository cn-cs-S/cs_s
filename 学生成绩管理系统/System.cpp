#include "System.hpp"
#include<iostream>
#include<vector>
using namespace std;

void System::interface()
{
    cout << "Press the enter to do what you want to do ?" << endl;
    cout << "1. 录入学生成绩" << endl;
    cout << "2. 查询学生成绩" << endl;
    cout << "3. 删除学生成绩" << endl;
    cout << "4. 修改学生成绩" << endl;
    cout << "0. 退出" << endl;
}

void System::operation()
{
    switch (getchar())
    {
    case '1':
        
        break;
    case '2':

        break;
    case '3':

        break;
    case '4':

        break;
    case '0':

        break;
    default:
        cout << "输入的指令有误,请重新输入" << endl;
        break;
    }
}

void entry(vector<Student>& stu){
    
}
    