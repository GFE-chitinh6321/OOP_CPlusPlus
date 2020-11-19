#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class Bill;
class Patient{
protected:
    char fullName[30];
    char address[30];
    int year;
public:
    void Input();
    void Output();
    friend void SortByYearOld(Bill *a, int n);
    friend void ShowListPatienUnder10YearOld(Bill *a, int n);
};

class Bill : public Patient
{
private:
    char disease[30];
    int hospitalFee;
public:
    void Input();
    void Output();
    void YearOld();
    int CountYearOld();
    friend void ShowPatientHospitalFeeMax(Bill *a, int n);
};

int Bill :: CountYearOld()
{
    int x = 0;
    x = 2020 - year;
    return x;
}
void Patient :: Input(){
    cout << "\tEnter full name: ";          fflush(stdin);      gets(fullName);
    cout << "\tEnter address: ";            fflush(stdin);      gets(address);
    cout << "\tEnter year: ";               cin >> year;
}

void Patient :: Output()
{
    cout << setw(15) << fullName;
    cout << setw(15) << address;
    cout << setw(15) << year;
}

void Bill :: Input()
{
    Patient :: Input();
    cout << "\tEnter disease: ";            fflush(stdin);      gets(disease);
    cout << "\tEnter hospital's fee: " ;    cin >> hospitalFee;
}

void Bill :: Output()
{
    Patient :: Output();
    cout << setw(15) << disease;
    cout << setw(20) << hospitalFee;

}

void Bill :: YearOld()
{
    int yearOld = 0;
    yearOld = 2020 - year;
    cout << setw(15) << yearOld << endl;
}

void Title()
{
    cout << setw(15) << "Full name";
    cout << setw(15) << "Address";
    cout << setw(15) << "Year";
    cout << setw(15) << "Disease";
    cout << setw(20) << "Hospital's Fee";
    cout << setw(15) << "Year Old" << endl;
}
void InputBill(Bill *a, int n)
{
    for(int i=0; i<n; i++){
        cout << "Enter bill " << i+1 << ": " << endl;
        a[i].Input();
    }
}

void OutputBill(Bill *a, int n)
{
    Title();
    for(int i=0; i<n; i++){
        a[i].Output();
        a[i].YearOld();
    }
}

void SortByYearOld(Bill *a, int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(a[i].year > a[j].year){
                Bill temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void ShowListPatienUnder10YearOld(Bill *a, int n)
{
    Title();
    for(int i=0; i<n; i++){
        if(a[i].CountYearOld() <= 10){
            a[i].Output();
            a[i].YearOld();
        }
    }
}

void ShowPatientHospitalFeeMax(Bill *a, int n)
{
    int max = a[0].hospitalFee;
    for(int i=1; i<n; i++){
        if(max < a[i].hospitalFee)
            max = a[i].hospitalFee;
    }
    for(int i=0; i<n; i++){
        if(max = a[i].hospitalFee)
        {
            Title();
            a[i].Output();
            a[i].YearOld();
            break;
        }
    }
}
int main()
{
    int n;
    cout << "Enter amount of bill: ";
    cin >> n;
    Bill *a = new Bill[n];
    InputBill(a, n);

    cout << "--------------------------------------------------------" << endl;
    cout << "LIST PATIENT: " << endl;
    OutputBill(a, n);

    SortByYearOld(a, n);
    cout << "--------------------------------------------------------" << endl;
    cout << "LIST PATIENT AFTER SORT: " << endl;
    OutputBill(a, n);

    cout << "--------------------------------------------------------" << endl;
    cout << "LIST PATIENT UNDER 10 YEAR OLD: " << endl;
    ShowListPatienUnder10YearOld(a, n);

    cout << "--------------------------------------------------------" << endl;
    cout << "PATIENT HAS MAX HOSPITALS'S FEE: " << endl;
    ShowPatientHospitalFeeMax(a, n);


    return 0;
}
