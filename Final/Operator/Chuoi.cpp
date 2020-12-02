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
    Chuoi (){
        str = "Chi Tinh";
    }
    Chuoi (string a){
        str = a;
    }
    void NhapChuoi();
    void XuatChuoi();
    Chuoi operator+ (Chuoi x);
    void operator= (Chuoi x);
    bool operator > (Chuoi x);
    bool operator < (Chuoi x);
    bool operator == (Chuoi x);
    friend istream& operator >> (istream& is, Chuoi &a);
    friend ostream& operator << (ostream& os, Chuoi a);
};

void Chuoi::NhapChuoi()
{
    cout << "Nhap chuoi: ";
    fflush(stdin);      getline(cin, str);
}

void Chuoi::XuatChuoi()
{
    cout << str << endl;
}

Chuoi Chuoi::operator+(Chuoi x)
{
    Chuoi ghep;
    ghep.str = this->str + x.str;
    return ghep;
}

void Chuoi::operator=(Chuoi x)
{

    this->str = x.str;

//    this->str = x.str;
//    return *this;
}

bool Chuoi::operator>(Chuoi x)
{
    if(this->str > x.str){
        return true;
    } else {
        return false;
    }
}

bool Chuoi::operator<(Chuoi x)
{
    if(this->str < x.str){
        return true;
    } else {
        return false;
    }
}

bool Chuoi::operator==(Chuoi x)
{
    if(this->str == x.str){
        return true;
    } else {
        return false;
    }
}

istream& operator >> (istream& is, Chuoi &a)
{
    cout << "Nhap chuoi: ";
    fflush(stdin);      getline(is, a.str);
    return is;
}

ostream& operator << (ostream& os, Chuoi a)
{
    os << a.str << endl;
    return os;
}

int main()
{
    Chuoi a;
    Chuoi b("Nhu Y");
    Chuoi c;
    c.NhapChuoi();
    cout << "Chuoi a: ";
    a.XuatChuoi();
    cout << "Chuoi b: " << b;
    cout << "Chuoi c: " << c;
    Chuoi d;
    d = a+b;
    cout << "Chuoi d = a+b: " << d;
    d = c;
    cout << "Chuoi d = c: " << d;
    if(a>b){
        cout << "a > b" << endl;
    }   else {
        cout << "a khac b" << endl;
    }
    if(a<b){
        cout << "a < b" << endl;
    }   else {
        cout << "a khac b" << endl;
    }
    if(a==b){
        cout << "a == b" << endl;
    }   else {
        cout << "a khac b" << endl;
    }

    return 0;


}
