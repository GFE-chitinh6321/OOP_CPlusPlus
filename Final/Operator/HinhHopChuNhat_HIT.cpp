#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class HHCN
{
private:
    float cDai;
    float cRong;
    float cCao;
public:
    HHCN(){
        cDai = 2;
        cRong = 3;
        cCao = 5;
    }
    float TheTich(){
        return cDai * cRong * cCao;
    }
    friend ostream& operator << (ostream& os, HHCN x);
    HHCN operator + (float d);
};

ostream& operator << (ostream& os, HHCN x)
{
    os << x.TheTich() << endl;
}

HHCN HHCN::operator+(float d)
{
    HHCN sum;
    sum.cDai = this->cDai + d;
    sum.cRong = this->cRong + d;
    sum.cCao = this->cCao + d;
    return sum;
}

int main()
{
    HHCN a, x;
    cout << "The tich: " << a;
    float d;
    cout << "Nhap d: "; cin >> d;
    x = a+d;
    cout << "The tich sau khi + d vao moi canh: " << x;
}
