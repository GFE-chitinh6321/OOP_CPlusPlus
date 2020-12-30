#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Chuoi
{
private:
    string str;
public:
    Chuoi(){
        str = "Chi Tinh";
    }
    Chuoi(string a){
        str = a;
    }
    void NhapChuoi();
    void XuatChuoi();
    Chuoi operator + (Chuoi x);
    Chuoi operator = (Chuoi x);
    bool operator > (Chuoi x);
    bool operator == (Chuoi x);
    friend istream& operator >> (istream& is, Chuoi &x);
    friend ostream& operator << (ostream& os, Chuoi x);
};

void Chuoi::NhapChuoi()
{
    fflush(stdin);
    getline(cin, str);
}

void Chuoi::XuatChuoi()
{
    cout << str << endl;
}

Chuoi Chuoi::operator+(Chuoi x)
{
    Chuoi sum;
    sum.str = this->str + x.str;
    return sum;
}

Chuoi Chuoi::operator=(Chuoi x)
{
    this->str = x.str;
    return *this;
}

bool Chuoi::operator > (Chuoi x)
{
    if(this->str > x.str){
        return true;
    } else {
        return false;
    }
}

bool Chuoi::operator == (Chuoi x)
{
    if(this->str == x.str){
        return true;
    } else {
        return false;
    }
}

istream& operator >> (istream& is, Chuoi &x)
{
    getline(is, x.str);
    return is;
}

ostream& operator << (ostream&os, Chuoi x)
{
    os << x.str << endl;
    return os;
}
int main()
{
    Chuoi a;
    Chuoi b(" Nhu Y");
    Chuoi c;
    cout << "Nhap chuoi c: ";
    c.NhapChuoi();
    cout << "Chuoi a: " << a;
    cout << "Chuoi b: " << b;
    cout << "Chuoi c: ";
    c.XuatChuoi();
    Chuoi d;
    d = a + b + c;
    cout << "Chuoi d: " << d;
    if (a == c){
        cout << "a == c" << endl;
    } else {
        cout << "a != c" << endl;
    }
    if (b > c){
        cout << "b > c" << endl;
    } else {
        cout << "b != c" << endl;
    }



}
