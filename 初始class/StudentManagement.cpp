#include<iostream>
#include"StudentManagement.hh"
using namespace std;

void Student::inputScore(){
    cout<<"请输入学生学号:"<<endl;
    cin>>number;
    cout<<"请输入学生姓名:"<<endl;
    cin>>name;
    cout<<"请输入学生c语言成绩:"<<endl;
    cin>>cLanguage;
    sumscore+=cLanguage;
    cout<<"请输入学生高数成绩:"<<endl;
    cin>>promath;
    sumscore+=promath;
    cout<<"请输入学生英语成绩:"<<endl;
    cin>>chinglish;
    sumscore+=chinglish;
}

void Student::showScore(){
    cout << "学号" << '\t' << number << endl;
    cout << "姓名" << '\t' << name << endl;
    cout << "c语言" << '\t' << cLanguage << endl;
    cout << "高数" << '\t' << promath << endl;
    cout << "英语" << '\t' << chinglish << endl;
    cout << "总分" << '\t' << sumscore << endl;
}

/*void Student::orderSort(){

}
void Student::deleteScore(){

}
void Student::searchStudent(){

}
*/