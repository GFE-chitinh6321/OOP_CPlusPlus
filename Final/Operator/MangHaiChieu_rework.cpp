#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Mang2D
{
private:
    float **a;
    int m, n;
public:
    Mang2D operator-();
    Mang2D operator+(Mang2D x);
    Mang2D operator-(Mang2D x); // tương tự
    friend istream& operator >> (istream& is, Mang2D &x);
    friend ostream& operator <<  (ostream& os, Mang2D x);
};

istream& operator >> (istream& is, Mang2D &x)
{
    cout << "Nhap kich thuoc ma tran mxn: ";
    is >> x.m >> x.n;
    x.a = new float*[x.m];
    for(int i=0; i<x.m; i++){
        x.a[i] = new float[x.n];
    }
    for(int i=0; i<x.m; i++){
        for(int j=0; j<x.n; j++){
            cout << "a[" << i+1 << "][" << j+1 << "] = ";
            is >> x.a[i][j];
        }
    }
    return is;
}

ostream& operator <<  (ostream& os, Mang2D x)
{
    for(int i=0; i<x.m; i++){
        for(int j=0; j<x.n; j++){
            os << x.a[i][j] << "  ";
        }
        os << endl;
    }
}

Mang2D Mang2D::operator-()
{
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            this->a[i][j] = -this->a[i][j];
        }
    }
    return *this;

}

Mang2D Mang2D::operator+(Mang2D x)
{
    Mang2D sum;
    sum.m = this->m;
    sum.n = this->n;
    sum.a = new float*[sum.m];
    for(int i=0; i<sum.m; i++){
        sum.a[i] = new float[sum.n];
    }
    for(int i=0; i<sum.m; i++){
        for(int j=0; j<sum.n; j++){
            sum.a[i][j] = this->a[i][j] + x.a[i][j];
        }
    }
    return sum;
}

int main()
{
    Mang2D a, b;
    cout << "Nhap mang a: " << endl;
    cin >> a;
    cout << "Nhap mang b: " << endl;
    cin >> b;
    cout << "------------------------------------------------" << endl;
    cout << "MANG A" << endl;
    cout << a;
    cout << "MANG B" << endl;
    cout << b;

    Mang2D c = a+b;
    cout << "MANG C" << endl;
    cout << c;
    return 0;


}
