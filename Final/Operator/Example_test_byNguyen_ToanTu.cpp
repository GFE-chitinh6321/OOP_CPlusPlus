#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class TamThuc
{
private:
    float a, b, c;
public:
    friend istream& operator >> (istream& is, TamThuc &x);
    friend ostream& operator << (ostream& os, TamThuc x);
    TamThuc operator +(TamThuc x);
};

istream& operator >> (istream& is, TamThuc &x)
{
    is >> x.a >> x.b >> x.c;
    return is;
}

ostream& operator << (ostream& os, TamThuc x)
{
    os << "F(x) = " << x.a << "x^2 ";
    if(x.b > 0){
        os << "+ " << x.b << "x ";
    } else {
        os << x.b;
    }
    if(x.c > 0){
        os << "+ " << x.c << endl;
    } else {
        os << x.c << endl;
    }
    return os;
}

TamThuc TamThuc::operator+(TamThuc x)
{
    TamThuc sum;
    sum.a = this->a + x.a;
    sum.b = this->b + x.b;
    sum.c = this->c + x.c;
    return sum;
}

int main()
{
    TamThuc x, y, z;
    cout << "Nhap tam thuc x: ";
    cin >> x;
    cout << "Nhap tam thuc y: ";
    cin >> y;
    cout << "Tam thuc x: " << x;
    cout << "Tam thuc x: " << y;
    z = x + y;
    cout << "Tam thuc z: " << z;
    return 0;

}
