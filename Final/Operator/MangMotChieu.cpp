#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Mang
{
private:
    float *a;
    int n;
public:
    void operator++ (); // sap xep mang tang dan
    void operator-- (); // tru di moi phan tu trong mang 2 don vi
    friend istream& operator >> (istream& is, Mang &x);
    friend ostream& operator << (ostream& os, Mang x);
};

void Mang::operator++()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Mang::operator--()
{
    for(int i=0; i<n; i++){
        a[i] = a[i] - 2;
    }
}

istream& operator >> (istream& is, Mang &x)
{
    cout << "Nhap so luong phan tu: ";  is >> x.n;
    x.a = new float[x.n];
    for(int i=0; i<x.n; i++){
        cout << "a[" << i+1 << "] = ";
        is >> x.a[i];
    }
    return is;
}

ostream& operator << (ostream& os, Mang x)
{
    for(int i=0; i<x.n; i++){
        os << x.a[i] << "  ";
    }
    os << endl;
    return os;
}

int main()
{
    Mang a;
    cin >> a;
    cout << "Mang a: " << a;
    ++a;
    cout << "Mang a sau khi sap xep: " << a;
    --a;
    cout << "Mang a sau khi tru 2: " << a;

    return 0;


}
