#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class CouponInformation
{
private:
    char codeCoupon[30];
    char dateCreate[30];
public:
    friend class Coupon;
};

class Bill
{
private:
    char product[30];
    float unitPrice;
    int amount;
public:
    friend class Coupon;
    friend float SumPrice(Bill x);
};

class Coupon
{
private:
    CouponInformation couponInformation;
    Bill *x;
    int n;
public:
    void Input();
    void Output();
};

void Coupon::Input()
{
    cout << "Enter information of coupon: " << endl;
    cout << "\t\tCode coupon: ";            fflush(stdin);         gets(couponInformation.codeCoupon);
    cout << "\t\tDate create: ";            fflush(stdin);         gets(couponInformation.dateCreate);
    cout << "Enter amount product: ";       cin >> n;
    x = new Bill[n];
    for(int i=0; i<n; i++){
        cout << "\tEnter information product " << i+1 << ": " << endl;
        cout << "\t\tProduct: ";            fflush(stdin);          gets(x[i].product);
        cout << "\t\tUnit price: ";         cin >> x[i].unitPrice;
        cout << "\t\tAmount: ";             cin >> x[i].amount;
    }
}

float SumPrice(Bill x)
{
    float sumPrice = 0;
    sumPrice = x.amount * x.unitPrice;
    return sumPrice;
}

void Title()
{
    cout << setw(15) << "Product";
    cout << setw(15) << "Unit price";
    cout << setw(15) << "Amount";
    cout << setw(15) << "Sum price" << endl;
}

void Coupon::Output()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << setw(30) << "COUPON BUY PRODUCT" << endl;
    cout << setw(20) << "Code coupon: " << couponInformation.codeCoupon;
    cout << setw(20) << "Date create: " << couponInformation.dateCreate << endl;
    cout << "-------------------------------------------------------------" << endl;
    Title();
    float totalPrice = 0;
    for(int i=0; i<n; i++){
        cout << setw(15) << x[i].product;
        cout << setw(15) << x[i].unitPrice;
        cout << setw(15) << x[i].amount;
        cout << setw(15) << SumPrice(x[i]) << endl;
        totalPrice += SumPrice(x[i]);
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << setw(45) << "Total" << setw(15) << totalPrice << endl;
    cout << "-------------------------------------------------------------" << endl;

}

int main()
{
    Coupon a;
    a.Input();
    a.Output();
    return 0;

}
