#pragma once
#include<string>
#include<vector>

using namespace std;
class Student{
    friend class System;
    public:
    Student(string name, string number);
    Student& setName(string name);
    Student& setNumber(string number);
    Student& setMath(double math);
    Student& setEnglish(double english);
    Student& setCLanguage(double cLanguage);
    Student& setPolitical(double political);
    Student& setSports(double sports);
    string getName() const;
    string getNumber() const;
    double getMath() const;
    double getEnglish() const;
    double getCLanguage() const;
    double getPolitical() const;
    double getSports() const; 
    double getGradeColumnPoints() const;

    private:
    string name;
    string number;
    double math = 0;
    double english = 0;
    double cLanguage = 0;
    double political = 0;
    double sports = 0;
    double gradeColumnPoints=0.000;
};