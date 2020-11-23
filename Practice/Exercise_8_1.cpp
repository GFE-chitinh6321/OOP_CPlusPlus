#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class ImportCoupon;

class Coupon
{
private:
    char codeCoupon[30];
    char dateCreate[30];
    char codeSupplier[30];
    char nameSupplier[30];
    char addressSupplier[30];
public:
    friend class ImportCoupon;

};

class Bill
{
private:
    char product[30];
    float unitPrice;
    int amount;
    float sumPrice;
public:
    friend class ImportCoupon;
    friend float SumPrice(Bill x);
    friend float TotalPrice(Bill x[], int n);
};

class ImportCoupon
{
private:
    Coupon coupon;
    Bill *x;
    int n;
public:
    void Input();
    void Output();

};

void ImportCoupon::Input()
{
    cout << "Enter information of coupon: " << endl;
    cout << "\tCode coupon: ";              cin >> coupon.codeCoupon;
    cout << "\tDate create: ";              fflush(stdin);          gets(coupon.dateCreate);
    cout << "\tCode supplier: ";            fflush(stdin);          gets(coupon.codeSupplier);
    cout << "\tName supplier: ";            fflush(stdin);          gets(coupon.nameSupplier);
    cout << "\tAddress supplier: ";         fflush(stdin);          gets(coupon.addressSupplier);
    cout << "Enter amount of product: ";    cin >> n;
    x = new Bill[n];
    for(int i=0; i<n; i++){
        cout << "\tEnter information product " << i+1 << ": " << endl;
        cout << "\t\tProduct: ";            fflush(stdin);          gets(x[i].product);
        cout << "\t\tUnit price: ";         cin >> x[i].unitPrice;
        cout << "\t\tAmount: ";             cin >> x[i].amount;
    }
}

void TitleBill()
{
    cout << setw(15) << "Product";
    cout << setw(15) << "Unit Price";
    cout << setw(15) << "Amount";
    cout << setw(15) << "Sum Price" << endl;
}

void ImportCoupon::Output()
{
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "IMPORT COUPON" << endl;
    cout << setw(25) << "Code coupon: " << coupon.codeCoupon;
    cout << setw(25) << "Date create: " << coupon.dateCreate << endl;
    cout << setw(25) << "Code Supplier: " << coupon.codeSupplier;
    cout << setw(25) << "Supplier: " << coupon.nameSupplier << endl;
    cout << setw(25) << "Address: " << coupon.addressSupplier << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    TitleBill();
    for(int i=0; i<n; i++){
        cout << setw(15) << x[i].product;
        cout << setw(15) << x[i].unitPrice;
        cout << setw(15) << x[i].amount;
        cout << setw(15) << SumPrice(x[i]) << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << setw(45) << "Total" << setw(15) << TotalPrice(x, n) << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

float SumPrice(Bill x)
{
    float sumPrice = 0;
    sumPrice = x.amount * x.unitPrice;
    return sumPrice;
}

float TotalPrice(Bill x[], int n)
{
    float totalPrice = 0;
    for(int i=0; i<n; i++){
        totalPrice += SumPrice(x[i]);
    }
    return totalPrice;
}

int main()
{
    ImportCoupon a;
    a.Input();
    a.Output();

    return 0;
}
