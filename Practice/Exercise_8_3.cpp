#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Coupon
{
    char codeCoupon[30];
    char dateInventory[30];
    char employeeInventory[30];
    char position[30];
    char roomInventory[30];
    char codeRoom[30];
    char manager[30];
public:
    friend class ReportInventoryAsset;
};

class Asset
{
private:
    char nameAsset[30];
    int amount;
    char status[30];
public:
    friend class ReportInventoryAsset;
};

class ReportInventoryAsset
{
private:
    Coupon coupon;
    Asset *x;
    int n;
public:
    void Input();
    void Output();

};

void ReportInventoryAsset::Input()
{
    cout << "Enter information coupon: " << endl;
    cout << "\tCode coupon: ";                  fflush(stdin);          gets(coupon.codeCoupon);
    cout << "\tDate inventory: ";                fflush(stdin);          gets(coupon.dateInventory);
    cout << "\tEmployee inventory: ";           fflush(stdin);          gets(coupon.employeeInventory);
    cout << "\tPosition: ";                     fflush(stdin);          gets(coupon.position);
    cout << "\tRoom inventory: ";               fflush(stdin);          gets(coupon.roomInventory);
    cout << "\tCode room: ";                    fflush(stdin);          gets(coupon.codeRoom);
    cout << "\tManager: ";                      fflush(stdin);          gets(coupon.manager);
    cout << "Enter amount of asset: ";          cin >> n;
    x = new Asset[n];
    for(int i=0; i<n; i++){
        cout << "Enter information asset " << i+1 << ": " << endl;
        cout << "\tAsset: ";                    fflush(stdin);          gets(x[i].nameAsset);
        cout << "\tAmount: ";                   cin >> x[i].amount;
        cout << "\tStatus: ";                   fflush(stdin);           gets(x[i].status);
    }
}

void Title()
{
    cout << setw(20) << "Asset";
    cout << setw(20) << "Amount";
    cout << setw(20) << "Status" << endl;
}

void ReportInventoryAsset::Output()
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << setw(35) << "REPORT INVENTORY ASSET" <<endl;
    cout << setw(20) << "Code coupon: " << coupon.codeCoupon;
    cout << setw(20) << "Date inventory: " << coupon.dateInventory << endl;
    cout << setw(20) << "Employee: " << coupon.employeeInventory;
    cout << setw(20) << "Position: " << coupon.position << endl;
    cout << setw(20) << "Room: " << coupon.roomInventory;
    cout << setw(20) << "Code room: " << coupon.codeRoom << endl;
    cout << setw(20) << "Manager: " << coupon.manager << endl;

    cout << "------------------------------------------------------------------------" << endl;
    Title();
    int totalAmount = 0;
    for(int i=0; i<n; i++){
        cout << setw(20) << x[i].nameAsset;
        cout << setw(20) << x[i].amount;
        cout << setw(20) << x[i].status << endl;
        totalAmount += x[i].amount;
    }
    cout << "------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Amount asset: " << n;
    cout << setw(20) << "Total amount: " << totalAmount << endl;
    cout << "------------------------------------------------------------------------" << endl;
}


int main()
{
    ReportInventoryAsset a;
    a.Input();
    a.Output();

    return 0;









}
