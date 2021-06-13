#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class TamThuc {
private:
    float a, b, c;
public:
    TamThuc(){
        a = 3;
        b = -2;
        c = -1;
    }
    TamThuc(float x, float y, float z){
        a = x;
        b = y;
        c = z;
    }
    TamThuc operator -- ();
    friend istream& operator >> (istream &is, TamThuc &tamThuc);
    friend ostream& operator << (ostream &os, TamThuc tamThuc);
};

TamThuc TamThuc::operator--(){
    this -> a = -this -> a;
    this -> b = -this -> b;
    this -> c = -this -> c;
    return *this;
}

istream& operator >> (istream &is, TamThuc &tamThuc){
    cout << "\ta = ";   is >> tamThuc.a;
    cout << "\tb = ";   is >> tamThuc.b;
    cout << "\tc = ";   is >> tamThuc.c;
    return is;
}

ostream& operator << (ostream &os, TamThuc tamThuc) {
    os << tamThuc.a << "x^2 ";
    if (tamThuc.b > 0)
        cout << "+ " << tamThuc.b << "x ";
    else {
        cout << tamThuc.b << "x ";
    }
    if (tamThuc.c > 0)
        cout << "+ " << tamThuc.c;
    else {
        cout << tamThuc.c;
    }
    return os;
}

int main()
{
    TamThuc a;
    TamThuc b(1, 2, 3);
    TamThuc c;
    cout << "Nhap tam thuc c:" << endl;
    cin >> c;
    cout << "Tam thuc a: " << a << endl;
    cout << "Tam thuc b: " << b << endl;
    cout << "Tam thuc c: " << c << endl;
    --c; // doi dau
    cout << "Tam thuc c sau khi doi dau: " << c << endl;
    return 0;
}
