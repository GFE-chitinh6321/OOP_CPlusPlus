#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>

using namespace std;

//Note
//Fix request: Basic salary 1.600.000 -> 160.000
//Tax threshold: 5.000.000 -> 500000

class Lecturers;

class Cadre
{
protected:
    char codeCadre[30];
    char codeUnit[30];
    int yearBirth;
    float coefficientsSalary;
    float allowanceEat;
    float insurrance;
public:
    friend float AllowanceStandClass(Lecturers x);
    friend float AllowanceMal(Lecturers x);
    friend void ShowListLecturersMustPayTaxes(Lecturers x[], int n);
};

class Lecturers : public Cadre
{
public:
    void Input();
    void Output();
};

void Title()
{
    cout << setw(15) << "Code cadre";
    cout << setw(15) << "Code unit";
    cout << setw(15) << "Year";
    cout << setw(15) << "Coe.Salary";
    cout << setw(15) << "Allo.Eat";
    cout << setw(15) << "Insurrance";
    cout << setw(15) << "Allo.Stand";
    cout << setw(15) << "Allo.Mal";
    cout << setw(20) << "Salary" << endl;
}

void Lecturers::Input()
{
//    cout << "Enter information lecturers: " << endl;
    cout << "\tCode cadre: ";               fflush(stdin);          gets(codeCadre);
    cout << "\tCode unit: ";                fflush(stdin);          gets(codeUnit);
    cout << "\tYear of Birth: ";            cin >> yearBirth;
    cout << "\tCoefficients Salary: ";      cin >> coefficientsSalary;
    cout << "\tAllowanceEat: ";             cin >> allowanceEat;
    cout << "\tInsurrance: ";               cin >> insurrance;
}

void Lecturers::Output()
{
    float salary = 0;
    float basicSalary = 0;
    basicSalary = 160000 * coefficientsSalary;
    salary = basicSalary + basicSalary * 0.25 + basicSalary * 0.1 + allowanceEat - insurrance;
    cout << setw(15) << codeCadre;
    cout << setw(15) << codeUnit;
    cout << setw(15) << yearBirth;
    cout << setw(15) << coefficientsSalary;
    cout << setw(15) << allowanceEat;
    cout << setw(15) << insurrance;
    cout << setw(15) << coefficientsSalary * 160000 * 0.25;
    cout << setw(15) << coefficientsSalary * 160000 * 0.1;
    cout << setw(20) << salary << endl;
}

void InputListLecturers(Lecturers x[], int n)
{
    for(int i=0; i<n; i++){
        cout << "Enter information of lecturer " << i+1 << ": " << endl;
        x[i].Input();
    }
}

void ShowListLecturers(Lecturers x[], int n)
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "LIST LECTURERS" << endl;
    Title();
    for(int i=0; i<n; i++){
        x[i].Output();
    }
}

//float AllowanceStandClass(Lecturers x)
//{
//    float allowanceStandClass = 0;
//    allowanceStandClass = x.coefficientsSalary * 160000 * 0.25;
//    return allowanceStandClass;
//}
//
//float AllowanceMal(Lecturers x)
//{
//    float allowanceMal = 0;
//    allowanceMal = x.coefficientsSalary * 160000 * 0.1;
//    return allowanceMal;
//}

void ShowListLecturersMustPayTaxes(Lecturers x[], int n)
{


    cout << "-----------------------------------------------------------" << endl;
    cout << "LIST LECTURERS MUST PAY TAXES" << endl;
    int count = 0;
    for(int i=0; i<n; i++){
        float salary = 0;
        float basicSalary = 0;
        basicSalary = 160000 * x[i].coefficientsSalary;
        salary = basicSalary + basicSalary * 0.25 + basicSalary * 0.1 + x[i].allowanceEat - x[i].insurrance;
        if(salary > 500000){
            x[i].Output();
            count++;
        }
    }
    if(count == 0){
        cout << "List empty!!";
    }
}

int main()
{
    Lecturers *a;
    int n;
    cout << "Enter amount of lecturers: ";
    cin >> n;
    a = new Lecturers[n];
    InputListLecturers(a, n);
    ShowListLecturers(a, n);
    ShowListLecturersMustPayTaxes(a, n);
    return 0;


}
