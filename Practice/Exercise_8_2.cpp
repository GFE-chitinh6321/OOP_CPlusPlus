#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

class ReportPoint;

class Student
{
private:
    char code[30];
    char name[30];
    char room[30];
    char course[30];
public:
    friend class ReportPoint;

};

class Project
{
private:
    char subject[30];
    int amountCredit;
    float point;
public:

};

class ReportPoint
{
private:
    Student student;
    Project *x;
public:
    void Input();
    void Output();
};

void ReportPoint::Input()
{
    cout << "Enter student's code: ";         fflush(stdin);      gets(student.code);
    cout << "Enter student's name: ";         fflush(stdin);      gets(student.name);
    cout << "Enter student's class: ";        fflush(stdin);      gets(student.room);
    cout << "Enter student's course: ";         fflush(stdin);      gets(student.course);
}

int main()
{




}
