#include <iostream>

using namespace std;

class Trinomial
{
private:
    double a, b, c;
public:
    Trinomial(){
        a = b = c;
    }
    Trinomial(double x, double y, double z){
        a = x;
        b = y;
        c = z;
    }
    Trinomial operator-();
    Trinomial operator+ (Trinomial x);
    Trinomial operator- (Trinomial x);
    friend ostream& operator << (ostream& os, Trinomial obj);
};
Trinomial Trinomial :: operator-()
{
    Trinomial w;
    w.a = -this -> a;
    w.b = -this -> b;
    w.c = -this -> c;
    return w;
}

Trinomial Trinomial :: operator+(Trinomial x)
{
    Trinomial w;
    w.a = a + x.a;
    w.b = b + x.b;
    w.c = c + x.c;
    return w;
}

Trinomial Trinomial :: operator-(Trinomial x)
{
    Trinomial w;
    w.a = this -> a - x.a;
    w.b = this -> b - x.b;
    w.c = this -> c - x.c;
    return w;
}

ostream& operator << (ostream& os, Trinomial obj)
{
    os << obj.a << "x^2 ";
    if(obj.b < 0)
        os << obj.b << "x ";
    else
        os << "+" << obj.b << "x ";
    if(obj.c < 0)
        os << obj.c << endl;
    else
        os << "+" << obj.c << endl;
}

int main()
{
    Trinomial tri01(4, 5, -7);
    Trinomial tri02(-2, 5, 3);
    Trinomial tri03, tri04, tri05, tri06;
    tri03 = -tri01;
    tri04 = -tri02;
    cout << "Trinomial 01: " << tri03;
    cout << "Trinomial 02: " << tri04;

    tri05 = tri03 + tri04;
    tri06 = tri03 - tri04;
    cout << "Sum trinomial: " << tri05;
    cout << "Mul trinomial: " << tri06;
    return 0;
}
