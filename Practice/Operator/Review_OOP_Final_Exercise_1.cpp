#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
        numerator = 5;
        denominator = 7;
    }
    Fraction(int x, int y){
        numerator = x;
        denominator = y;
    }
    void Input();
    void Output();
    Fraction operator + (Fraction x);
    Fraction operator - (Fraction x);
    Fraction operator * (Fraction x);
    Fraction operator / (Fraction x);
    Fraction operator -- ();
    friend istream& operator >> (istream &is, Fraction &x);
    friend ostream& operator << (ostream &os, Fraction x);
};

void Fraction::Input()
{
    cout << "\tEnter numerator: ";  cin >> numerator;
    cout << "\tEnter denominator";  cin >> denominator;
}

void Fraction::Output()
{
    cout << numerator << "/" << denominator << endl;
}


Fraction Fraction::operator + (Fraction x)
{
    Fraction sum;
    sum.numerator = this->numerator * x.denominator + this->denominator * x.numerator;
    sum.denominator = this->denominator * x.denominator;
    return sum;
}

Fraction Fraction::operator - (Fraction x)
{
    Fraction sub;
    sub.numerator = this->numerator * x.denominator - this->denominator * x.numerator;
    sub.denominator = this->denominator * x.denominator;
    return sub;
}

Fraction Fraction::operator * (Fraction x)
{
    Fraction mul;
    mul.numerator = this->numerator * x.numerator;
    mul.denominator = this->denominator * x.denominator;
    return mul;
}

Fraction Fraction::operator / (Fraction x)
{
    Fraction div;
    div.numerator = this->numerator * x.denominator;
    div.denominator = this->denominator * x.numerator;
    return div;
}

int GreatestCommonDivisor(int a, int b)
{
    if(a % b == 0)
        return b;
    return GreatestCommonDivisor(b, a%b);
}

Fraction Fraction::operator--()
{
    int greatestCommonDivisor = GreatestCommonDivisor(this->numerator, this->denominator);
    this->numerator = this->numerator / greatestCommonDivisor;
    this->denominator = this->denominator / greatestCommonDivisor;
    return *this;
}

istream& operator >> (istream &is, Fraction &x)
{
    cout << "\tEnter numerator: ";  is >> x.numerator;
    cout << "\tEnter denominator: ";    is >> x.denominator;
    return is;
}

ostream& operator << (ostream &os, Fraction x)
{
    os << x.numerator << "/" << x.denominator << endl;
    return os;
}

int main()
{
    Fraction a;
    Fraction b(2, 5);
    Fraction z;
    cout << "Enter fraction z: " << endl;
    cin >> z;
    cout << "Fraction z: " << z;
    Fraction c;
    c = a+b;
    cout << "Result sum: " << c;
    c = a-b;
    cout << "Result sub: " << c;
    c = a*b;
    cout << "Result mul: " << c;
    --c;
    cout << "Result mul (minimal fractions): " << c;
    c = a/b;
    cout << "Result div: " << c;

    return 0;

}
