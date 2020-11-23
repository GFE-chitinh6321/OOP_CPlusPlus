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
    int amountCredits;
    float point;
public:
    friend class ReportPoint;
    friend float MediumPoint(Project x[], int n);
};

class ReportPoint
{
private:
    Student student;
    Project *x;
    int n;
public:
    void Input();
    void Output();
};

void TitleProject()
{
    cout << setw(15) << "Subject";
    cout << setw(20) << "Amount credtis";
    cout << setw(15) << "Point" << endl;
}

void ReportPoint::Input()
{
    cout << "Enter student's code: ";           fflush(stdin);      gets(student.code);
    cout << "Enter student's name: ";           fflush(stdin);      gets(student.name);
    cout << "Enter student's class: ";          fflush(stdin);      gets(student.room);
    cout << "Enter student's course: ";         fflush(stdin);      gets(student.course);
    cout << "Enter amount of project: ";        cin >> n;
    x = new Project[n];
    for(int i=0; i<n; i++){
        cout << "\tEnter information project " << i+1 << ": " << endl;
        cout << "\t\tEnter name project: ";     fflush(stdin);      gets(x[i].subject);
        cout << "\t\tEnter amount credits: ";   cin >> x[i].amountCredits;
        cout << "\t\tEnter point: ";            cin >> x[i].point;
    }
}

void ReportPoint::Output()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "REPORT POINT" << endl;
    cout << setw(15) << "Code: " << student.code;
    cout << setw(15) << "Name: " << student.name << endl;
    cout << setw(15) << "Class: " << student.room;
    cout << setw(15) << "Course: " << student.course << endl;
    cout << "Table point: " << endl;
    cout << "--------------------------------------------------------------" << endl;
    TitleProject();
    for(int i=0; i<n; i++){
        cout << setw(15) << x[i].subject;
        cout << setw(20) << x[i].amountCredits;
        cout << setw(15) << x[i].point << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << right << setw(35) << "Medium Score" << setw(15) << MediumPoint(x, n) << endl;
    cout << "--------------------------------------------------------------" << endl;
}

float MediumPoint(Project x[], int n)
{
    float sumPoint = 0;
    int numCreadits = 0;
    for(int i=0; i<n; i++){
        sumPoint += x[i].point * x[i].amountCredits;
        numCreadits += x[i].amountCredits;
    }
    float mediumPoint = sumPoint/(1.0*numCreadits);
    return mediumPoint;
}

int main()
{
    ReportPoint a;
    a.Input();
    a.Output();

    return 0;
}
