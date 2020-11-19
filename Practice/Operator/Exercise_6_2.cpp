#include <iostream>

using namespace std;

class Fraction{
private:
    int TS;
    int MS;
public:
    friend istream& operator >> (istream& input, Fraction &fraction);
    friend ostream& operator << (ostream& output, Fraction fraction);
    Fraction operator+ (Fraction a);
    Fraction operator- (Fraction a);
    Fraction operator* (Fraction a);
    Fraction operator/ (Fraction a);
};

istream& operator >> (istream& input, Fraction &fraction){
    cout << "\tEnter numerator: ";
    input >> fraction.TS;
    cout << "\tEnter denominator: ";
    input >> fraction.MS;
}
ostream& operator << (ostream& output, Fraction fraction){
    cout << fraction.TS << "/" << fraction.MS << endl;
}
Fraction Fraction::operator+(Fraction a){
    Fraction sum;
    sum.TS = (TS * a.MS) + (MS * a.TS);
    sum.MS = (MS * a.MS);
    return sum;
}

Fraction Fraction::operator-(Fraction a){
    Fraction sub;
    sub.TS = TS * a.MS - MS * a.TS;
    sub.MS = TS * a.MS;
    return sub;
}

Fraction Fraction::operator*(Fraction a){
    Fraction mul;
    mul.TS = TS * a.TS;
    mul.MS = MS * a.MS;
    return mul;
}

Fraction Fraction::operator/(Fraction a){
    Fraction div;
    div.TS = TS * a.MS;
    div.MS = MS * a.TS;
    return div;
}

int main()
{
    Fraction a, b;
    cout << "Enter fraction a: " << endl;
    cin >> a;
    cout << "Enter fraction b: " << endl;
    cin >> b;

    Fraction c = a + b;
    cout << "Sum: " << c;
    Fraction d = a - b;
    cout << "Subtraction: " << d;
    Fraction e = a * b;
    cout << "Multiplication: " << e;
    Fraction f = a / b;
    cout << "Division: " << f;


    return 0;
}





















