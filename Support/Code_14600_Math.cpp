#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class NhiThuc {
private:
    float a, b;
public:
    NhiThuc(){
        a = 0;
        b = 0;
    }
    NhiThuc(float a, float b) {
        this -> a = a;
        this -> b = b;
    }
    NhiThuc operator -- ();
    friend istream& operator >> (istream &is, NhiThuc &nhiThuc);
    friend ostream& operator << (ostream &os, NhiThuc nhiThuc);
};

istream& operator >> (istream &is, NhiThuc &nhiThuc) {
    cout << "Nhap he so a, b:" << endl;
    cout << "\ta: ";
    is >> nhiThuc.a;
    cout << "\tb: ";
    is >> nhiThuc.b;
    return is;
}

ostream& operator << (ostream &os, NhiThuc nhiThuc) {
    os << nhiThuc.a << "x ";
    if(nhiThuc.b >= 0){
        os << "+ " << nhiThuc.b;
    } else {
        os << nhiThuc.b;
    }
    return os;
}

NhiThuc NhiThuc::operator--() {
    this->a = -this->a;
    this->b = -this->b;
    return *this;
}



int main()
{
    NhiThuc a;
    NhiThuc b(5, 6);
    NhiThuc c;
    cin >> c;
    cout << "Nhi thuc a: " << a << endl;
    cout << "Nhi thuc b: " << b << endl;
    cout << "Nhi thuc c: " << c << endl;
    --c;
    cout << "Nhi thuc c sau khi doi dau: " << c << endl;
    return 0;
}
