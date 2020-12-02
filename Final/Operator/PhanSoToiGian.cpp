#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
private:
    float tu;
    float mau;
public:
    PhanSo(){
        tu = 6;
        mau = 3;
    }
    PhanSo(float x, float y){
        tu = x;
        mau = y;
    }
    PhanSo operator+ (PhanSo x);
    PhanSo operator- (PhanSo x);
    PhanSo operator* (PhanSo x);
    PhanSo operator/ (PhanSo x);
    PhanSo operator-- (); // rut gon phan so thanh phan so toi gian
    friend istream& operator >> (istream& is, PhanSo &a);
    friend ostream& operator << (ostream& os, PhanSo a);

};

PhanSo PhanSo::operator+(PhanSo x)
{
    PhanSo tong;
    tong.tu = this->tu*x.mau + this->mau*x.tu;
    tong.mau = this->mau * x.mau;
    return tong;
}

PhanSo PhanSo::operator-(PhanSo x)
{
    PhanSo hieu;
    hieu.tu = this->tu*x.mau - this->mau*x.tu;
    hieu.mau = this->mau * x.mau;
    return hieu;
}

PhanSo PhanSo::operator*(PhanSo x)
{
    PhanSo tich;
    tich.tu = this->tu * x.tu;
    tich.mau = this->mau * x.mau;
    return tich;
}

PhanSo PhanSo::operator/(PhanSo x)
{
    PhanSo thuong;
    thuong.tu = this->tu * x.mau;
    thuong.mau = this->mau * x.tu;
    return thuong;
}

int UCLN(int a, int b)
{
    if(a%b == 0){
        return b;
    }
    return UCLN(b, a%b);
}

PhanSo PhanSo::operator--()
{
    int ucln = UCLN(this->tu, this->mau);
    this->tu = this->tu / ucln;
    this->mau = this->mau / ucln;
    return *this;
}

istream& operator >> (istream& is, PhanSo &a)
{
    cout << "\tTu so: ";    is >> a.tu;
    cout << "\tMau so: ";   is >> a.mau;
    return is;
}

ostream& operator << (ostream& os, PhanSo a)
{
    os << a.tu << "/" << a.mau << endl;
    return os;
}

int main()
{
    PhanSo a;
    PhanSo b(4, 9);
    PhanSo c;
    cout << "Nhap phan so c: " << endl;
    cin >> c;
    PhanSo d;
    d = a + b;
    cout << "Tong a+b: " << d;
    --d;
    cout << "Tong (rut gon): " << d;
    d = a - b;
    cout << "Hieu a-b: " << d;
    d = a * b;
    cout << "Tich a*b: " << d;
    d = a / b;
    cout << "Thuong a/b: " << d;
    cout << "Phan so a: " << a;
    --a;
    cout << "Phan so a (rut gon): " << a;
    cout << "Phan so b: " << b;
    cout << "Phan so c: " << c;

    return 0;
}
