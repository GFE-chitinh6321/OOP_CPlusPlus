#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class HinhHopCN
{
private:
    float chieuDai;
    float chieuRong;
    float chieuCao;
public:
    HinhHopCN(){
        chieuDai = 5;
        chieuRong = 2;
        chieuCao = 3;
    }
    float TinhTheTich(float a, float b, float c);
    friend ostream&operator << (ostream& os, HinhHopCN x);
    HinhHopCN operator+ ();
};

float HinhHopCN::TinhTheTich(float a, float b, float c)
{
    float v = 0;
    v = a * b * c;
    return v;
}

ostream&operator << (ostream& os, HinhHopCN x)
{
    float theTich = 0;
    theTich = x.TinhTheTich(x.chieuDai, x.chieuRong, x.chieuCao);
    os << theTich;
}

HinhHopCN HinhHopCN::operator+()
{
    int d;
    cout << "Nhap d: "; cin >> d;
    this->chieuDai = this->chieuDai + d;
    this->chieuRong = this->chieuRong + d;
    this->chieuCao = this->chieuCao + d;
    return *this;
}

int main()
{
    HinhHopCN a;
    cout << "The tich: " << a << endl;
    +a;
    cout << "The tich sau khi tang d vao moi canh: " << a << endl;
}
