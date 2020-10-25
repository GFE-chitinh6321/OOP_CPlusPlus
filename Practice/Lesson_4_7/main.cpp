#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
class Company;
class Date
{
private:
    int day;
    int month;
    int year;
public:
    void inputDate();
    void showDate();
    friend void SumRevenue2015(Company company[], int n);
};

class Address
{
private:
    char phoneN[12];
    char ward[30];
    char district[30];
    char city[30];
public:
    friend class Company;
    friend void FindHaNoiCity(Company company[], int n);
};

class Company
{
private:
    int code;
    char name[30];
    Date date;
    Address address;
    char manager[30];
    long revenue;
public:
    void inputCompany();
    void showCompany();
    friend void FindHaNoiCity(Company company[], int n);
    friend void SumRevenue2015(Company company[], int n);
    friend void FixInformationCompany(Company company[], int n);
};

void Date::inputDate(){
    cout << "\t day: ";      cin >> day;
    cout << "\t month: ";    cin >> month;
    cout << "\t year: ";     cin >> year;
}
void Date::showDate(){
    cout << setw(15) << day << "/" << month << "/" << year;
}

void Company::inputCompany(){
    cout << "Enter code company: ";             cin >> code;
    cout << "Enter company: ";                  fflush(stdin);          gets(name);
    cout << "Enter date of incorporation: \n";  date.inputDate();
    cout << "Enter address: " << endl;
    cout << "\t phone number: ";                fflush(stdin);          gets(address.phoneN);
    cout << "\t ward : ";                       fflush(stdin);          gets(address.ward);
    cout << "\t district: ";                    fflush(stdin);          gets(address.district);
    cout << "\t city: ";                        fflush(stdin);          gets(address.city);
    cout << "Enter manager: ";                  fflush(stdin);          gets(manager);
    cout << "Enter revenue of company: ";       cin >> revenue;
}

void Company::showCompany(){
    cout << setw(15) << code;
    cout << setw(15) << name;
    date.showDate();
    cout << setw(15) << address.phoneN;
    cout << setw(15) << address.ward;
    cout << setw(15) << address.district;
    cout << setw(15) << address.city;
    cout << setw(15) << manager;
    cout << setw(15) << revenue << endl;
}
void Title(){
    cout << setw(15) << "Code";
    cout << setw(15) << "Company";
    cout << setw(22) << "Date";
    cout << setw(15) << "Phone";
    cout << setw(15) << "Ward";
    cout << setw(15) << "District";
    cout << setw(15) << "City";
    cout << setw(15) << "Manager";
    cout << setw(15) << "Revenue" << endl;
}

void FindHaNoiCity(Company company[], int n){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "COMPANY IN HANOI" << endl;
    for(int i=0; i<n; i++){
        if(strcmp(company[i].address.city, "Ha Noi") == 0)
            company[i].showCompany();
    }
}
void SumRevenue2015(Company company[], int n){
    long SumRevenue = 0;
    cout << "-------------------------------------------------------------------------" << endl;
    for(int i=0; i<n; i++){
        if(company[i].date.year == 2015)
            SumRevenue += company[i].revenue;
    }
    cout << "Total revenue in 2015: " << SumRevenue << endl;
}

void FixInformationCompany(Company company[], int n){
    int fixCodeCompany;
    cout << "Enter code company you need fix: ";        cin >> fixCodeCompany;
    for(int i=0; i<n; i++){
        if(fixCodeCompany == company[i].code)
            company[i].inputCompany();
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "COMPANY LIST AFTER FIX" << endl;
    Title();
    for(int i=0; i<n; i++){
        company[i].showCompany();
    }
}

int main()
{
    Company *company;
    int n;
    cout << "Enter amount of company: ";        cin >> n;
    company = new Company[n];

    for(int i=0; i<n; i++){
        cout << "Enter information company " << i+1 << ": " << endl;
        company[i].inputCompany();
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "COMPANY LIST" << endl;
    Title();
    for(int i=0; i<n; i++){
        company[i].showCompany();
    }

    FindHaNoiCity(company, n);
    SumRevenue2015(company, n);
    FixInformationCompany(company, n);

    return 0;
}












