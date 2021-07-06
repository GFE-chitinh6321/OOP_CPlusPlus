#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class PhuongTrinhBacHai {
private:
    float a, b, c;
public:
    friend istream& operator >> (istream &is, PhuongTrinhBacHai &phuongTrinhBacHai);
    friend ostream& operator << (ostream &os, PhuongTrinhBacHai phuongTrinhBacHai);
    PhuongTrinhBacHai operator + (PhuongTrinhBacHai phuongTrinhBacHai);
    float operator ++ ();
};

istream& operator >> (istream &is, PhuongTrinhBacHai &phuongTrinhBacHai){
    cout << "\ta = ";   is >> phuongTrinhBacHai.a;
    cout << "\tb = ";   is >> phuongTrinhBacHai.b;
    cout << "\tc = ";   is >> phuongTrinhBacHai.c;
    return is;
}

ostream& operator << (ostream &os, PhuongTrinhBacHai phuongTrinhBacHai) {
    os << phuongTrinhBacHai.a << "x^2 ";
    if (phuongTrinhBacHai.b >= 0)
        cout << "+ " << phuongTrinhBacHai.b << "x ";
    else {
        cout << phuongTrinhBacHai.b << "x ";
    }
    if (phuongTrinhBacHai.c >= 0)
        cout << "+ " << phuongTrinhBacHai.c << " = 0";
    else {
        cout << phuongTrinhBacHai.c << " = 0";
    }
    return os;
}

PhuongTrinhBacHai PhuongTrinhBacHai::operator+(PhuongTrinhBacHai phuongTrinhBacHai) {
    PhuongTrinhBacHai sum;
    sum.a = this->a + phuongTrinhBacHai.a;
    sum.b = this->b + phuongTrinhBacHai.b;
    sum.c = this->c + phuongTrinhBacHai.c;
    return sum;
}

float PhuongTrinhBacHai :: operator++(){
    return this->a + this->b + this->c;
}

int main()
{
    PhuongTrinhBacHai P, Q;
    cout << "Nhap he so phuong trinh P: " << endl;
    cin >> P;
    cout << "Nhap he so phuong trinh Q: " << endl;
    cin >> Q;
    cout << "Phuong trinh P: " << P << endl;
    cout << "Phuong trinh Q: " << Q << endl;
    PhuongTrinhBacHai K;
    K = P + Q;
    cout << "Phuong trinh K: " << K << endl;
    cout << "Tong he so phuong trinh K: " << ++K;
    return 0;
}
