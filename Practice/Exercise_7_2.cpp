#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class School
{
private:
    char nameSchool[30];
    char dateCreateSchool[30];
public:
    friend class Faculty;
};

class Faculty
{
private:
    char nameFaculty[30];
    char dateCreateFaculty[30];
    School x;
public:
    void Input();
    void Output();
};

class Person
{
protected:
    char name[30];
    char birth[30];
    char address[30];
public:
    void Input();
    void Output();
    Person(){
        strcpy(name, "Chi Tinh");
        strcpy(birth, "6321");
        strcpy(address, "Vietnam");
    }
};

class Student : public Person
{
private:
    Faculty y;
    char room[30];
    float score;
public:
    void Input();
    void Output();
};

void Faculty::Input()
{
    cout << "Enter information school: " << endl;
    cout << "\tSchool: ";               fflush(stdin);          gets(x.nameSchool);
    cout << "\tDate create school: ";   fflush(stdin);           gets(x.dateCreateSchool);
    cout << "Enter information faculty: " << endl;
    cout << "\tFaculty: ";              fflush(stdin);          gets(nameFaculty);
    cout << "\tDate create faculty: ";  fflush(stdin);          gets(dateCreateFaculty);
}
void Faculty::Output()
{
    cout << setw(15) << x.nameSchool;
    cout << setw(15) << x.dateCreateSchool;
    cout << setw(15) << nameFaculty;
    cout << setw(15) << dateCreateFaculty;
}

void Person::Input()
{
    cout << "Enter information person: " << endl;
    cout << "\tName: ";                 fflush(stdin);          gets(name);
    cout << "\tBirth: ";                fflush(stdin);          gets(birth);
    cout << "\tAddress: ";              fflush(stdin);          gets(address);
}

void Person::Output()
{
    cout << setw(15) << name;
    cout << setw(15) << birth;
    cout << setw(15) << address;
}

void Title()
{
    cout << setw(15) << "School";
    cout << setw(15) << "Code";
    cout << setw(15) << "Faculty";
    cout << setw(15) << "Code";
    cout << setw(15) << "Name";
    cout << setw(15) << "Birth";
    cout << setw(15) << "Address";
    cout << setw(15) << "Class";
    cout << setw(15) << "Score" << endl;
}

void Student::Input()
{
    y.Input();
    Person::Input();
    cout << "\tClass: ";                fflush(stdin);          gets(room);
    cout << "\tScore: ";                cin >> score;
}

void Student::Output()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "REPORT STUDENT" << endl;
    Title();
    cout << "------------------------------------------------------------------" << endl;
    y.Output();
    Person::Output();
    cout << setw(15) << room;
    cout << setw(15) << score << endl;
    cout << "------------------------------------------------------------------" << endl;
}


int main()
{
    Student a;
    a.Input();
    a.Output();

    return 0;
}
