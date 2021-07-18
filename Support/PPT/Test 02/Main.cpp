#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    float *a;
    int n;
public:
    Array(){

    }
    float operator++(); // tinh tong mang
    bool operator==(Array x); // so sanh tong
    void operator--(); // dao nguoc mang
    friend istream& operator >> (istream &is, Array &obj);
    friend ostream& operator << (ostream &os, Array obj);
};

istream& operator >> (istream &is, Array &obj)
{
    cout << "Nhap so phan tu cua mang: ";
    is >> obj.n;
    obj.a = new float[obj.n];
    for(int i=0; i<obj.n; i++){
        cout << "a[" << i << "] = ";
        is >> obj.a[i];
    }
    return is;
}
ostream& operator << (ostream &os, Array obj)
{
    for(int i=0; i<obj.n; i++){
        os << obj.a[i] << "  ";
    }
    os << endl;
    return os;
}

float Array :: operator++()
{
    float sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}

bool Array :: operator==(Array x)
{
    float sum1 = 0;
    float sum2 = 0;
    for(int i=0; i<this->n; i++){
        sum1 += this->a[i];
    }
    for(int i=0; i<x.n; i++){
        sum2 += x.a[i];
    }
    if (sum1 == sum2) {
        return true;
    } else {
        return false;
    }
}

void Array :: operator--()
{
    for(int i=0;i<=n/2;i++) {
    int temp = a[i];
    a[i] = a[n-1-i];
    a[n-1-i] = temp;
  }
}



int main()
{
    Array x, y;
    cout << "Nhap mang X:" << endl;
    cin >> x;
    cout << "Nhap mang Y:" << endl;
    cin >> y;
    cout << "Mang X: " << x;
    cout << "Mang Y: " << y;
    cout << "Tong mang X: " << ++x << endl;
    cout << "Tong mang Y: " << ++y << endl;
    cout << "Ket qua so sanh mang: ";
    if (x==y){
        cout << "hai mang co tong bang nhau." << endl;
    } else {
        cout << "hai mang co tong khong bang nhau." << endl;
    }
    --x;
    cout << "Mang X sau khi dao nguoc: " << x << endl;




}
