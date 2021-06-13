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
        a = 5;
        b = -2;
        c = -3;
    }
    TamThuc(float a, float b, float c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    TamThuc operator -- ();
    friend istream& operator >> (istream &is, TamThuc &tamThuc);
    friend ostream& operator << (ostream &os, TamThuc tamThuc);
};

istream& operator >> (istream &is, TamThuc &tamThuc) {
    cout << "Nhap tam thuc: " << endl;
    cout << "\t a: ";   is >> tamThuc.a;
    cout << "\t b: ";   is >> tamThuc.b;
    cout << "\t c: ";   is >> tamThuc.c;
    return is;
}

ostream& operator << (ostream &os, TamThuc tamThuc) {
    os << tamThuc.a << "x^2 ";
    if (tamThuc.b >= 0)
        cout << "+ " << tamThuc.b << "x ";
    else
        cout << tamThuc.b << "x ";
    if (tamThuc.c >= 0)
        cout << "+ " << tamThuc.c;
    else
        cout << tamThuc.c;
    return os;
}

TamThuc TamThuc::operator--() {
    this->a = -this->a;
    this->b = -this->b;
    this->c = -this->c;
    return *this;
}

int main()
{
    TamThuc a;
    TamThuc b(1, 2, 3);
    TamThuc c;
    cin >> c;
    cout << "Tam thuc a: " << a << endl;
    cout << "Tam thuc b: " << b << endl;
    cout << "Tam thuc c: " << c << endl;
    --c;
    cout << "Tam thuc c sau khi doi dau: " << c << endl;
    return 0;
}
