#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class CubicEquation
{
private:
    float a, b, c, d;
public:
    CubicEquation(){
        a = 2, b = 3, c = -2, d = 1;
    }

    CubicEquation(float x, float y, float z, float t){
        a = x, b = y, c = z, d = t;
    }

    void Output();
    CubicEquation operator + (CubicEquation x);
    CubicEquation operator ++ ();
    friend istream& operator >> (istream& is, CubicEquation &x);
};

void CubicEquation::Output()
{
    cout << a << "x^3 ";
    if(b<0){
        cout << b << "x^2 ";
    } else {
        cout << "+ " << b << "x^2 ";
    }
    if(c<0){
        cout << c << "x ";
    } else {
        cout << "+ " << c << "x ";
    }
    if(d<0){
        cout << d << endl;
    } else {
        cout << "+ " << d << endl;
    }
}

CubicEquation CubicEquation::operator+(CubicEquation x)
{
    CubicEquation sum;

    sum.a = this->a + x.a;
    sum.b = this->b + x.b;
    sum.c = this->c + x.c;
    sum.d = this->d + x.d;

    return sum;
}


CubicEquation CubicEquation::operator++()
{
    float *e;
    e = new float[3];
    e[0] = a, e[1] = b; e[2] = c, e[3] = d;
    for(int i=0; i<4; i++){
        for(int j=i; j<4; j++){
            if(e[i] > e[j]){
                float temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    a = e[0], b = e[1], c = e[2], d = e[3];
}

istream& operator >> (istream& is, CubicEquation &x)
{
    cout << "\tEnter coefficients: ";
    is >> x.a >> x.b >> x.c >> x.d;
}

int main()
{
    CubicEquation a;
    CubicEquation b(-1, 2, 5, -3);
    CubicEquation c, d;

    cout << "Enter cubic equation c: " << endl;
    cin >> c;
    cout << "Cubic equation a: ";
    a.Output();
    cout << "Cubic equation b: ";
    b.Output();
    cout << "Cubic equation c: ";
    c.Output();
    d = a + c;
    cout << "Result sum cubic equation a & c: ";
    d.Output();
    ++b;
    cout << "Cubic equation b after sort coefficients: ";
    b.Output();

    return 0;
}
