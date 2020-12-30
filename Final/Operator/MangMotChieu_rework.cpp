#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Mang1D
{
private:
    float *a;
    int n;
public:
    void operator++();
    void operator--();
    friend istream& operator >> (istream& is, Mang1D &x);
    friend ostream& operator << (ostream& os, Mang1D x);
};

void Mang1D::operator++()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
//                float temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
                swap(a[i], a[j]);
            }
        }
    }
}

void Mang1D::operator--()
{
    for(int i=0; i<n; i++){
        this->a[i] = a[i] - 2;
    }
}

istream& operator >> (istream& is, Mang1D &x)
{
    cout << "Nhap so luong phan tu: ";  cin >> x.n;
    x.a = new float[x.n];
    for(int i=0; i<x.n; i++){
        cout << "a[" << i+1 << "] = ";
        is >> x.a[i];
    }
    return is;
}

ostream& operator << (ostream& os, Mang1D x)
{
    for(int i=0; i<x.n; i++){
        os << x.a[i] << "  ";
    }
    os << endl;
    return os;
}

int main()
{
    Mang1D a, b;
    cout << "Nhap mang a:" << endl;
    cin >> a;
    cout << "Nhap mang b:" << endl;
    cin >> b;
    cout << "------------------------------------" << endl;
    cout << "MANG A:\t" << a;
    cout << "MANG B:\t" << b;
    ++a;
    cout << "Mang a sau khi sap xep: " << a;
    --b;
    cout << "Mang b sau khi tru 2 don vi moi phan tu: " << b;
    return 0;


}
