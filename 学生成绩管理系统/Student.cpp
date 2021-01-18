#include<iostream>
#include<string>
#include<vector>
#include"Student.hpp"
using namespace std;

Student::Student(string name, string number){
    this->name = name;
    this->number = number;
    return ;
}

Student& Student::setName(string name){
    this->name = name;
    return *this;
}

Student& Student::setNumber(string number){
    this->number = number;
    return *this;
}

Student& Student::setMath(double math){
    gradeColumnPoints  -= (this->math - 60) / 10;
    this->math = math;
    gradeColumnPoints += (math - 60) / 10;
    return *this;
}

Student& Student::setEnglish(double english){
    gradeColumnPoints  -= (this->english - 60) / 10;
    this->english = english;
    gradeColumnPoints += (english - 60) / 10;
    return *this;
}

Student& Student::setCLanguage(double cLanguage){
    gradeColumnPoints  -= (this->cLanguage - 60) / 10;
    this->cLanguage = cLanguage;
    gradeColumnPoints += (cLanguage - 60) / 10;
    return *this;
}

Student& Student::setPolitical(double political){
    gradeColumnPoints  -= (this->political - 60) / 10;
    this->political = political;
    gradeColumnPoints += (political - 60) / 10;
    return *this;
}

Student& Student::setSports(double sports){
    gradeColumnPoints  -= (this->sports - 60) / 10;
    this->sports = sports;
    gradeColumnPoints += (sports - 60) / 10;
    return *this;
}

string Student::getName() const{
    return name;
}

string Student::getNumber() const{
    return number;
}

double Student::getMath() const{
    return math;
}

double Student::getEnglish() const{
    return english;
}

double Student::getCLanguage() const{
    return cLanguage;
}

double Student::getPolitical() const{
    return political;
}

double Student::getSports() const{
    return sports;
}

double Student::getGradeColumnPoints() const{
    return gradeColumnPoints;
}
