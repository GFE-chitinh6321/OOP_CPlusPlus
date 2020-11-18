#include <iostream>

using namespace std;

class Trinomial
{
private:
    float a;
    float b;
    float c;
public:
    Trinomial(){
        a = b= c;
    }
    Trinomial(float x, float y, float z){
        a = x;
        b = y;
        c = z;
    }
    friend ostream& operator << (ostream& os, Trinomial x);
    Trinomial operator-();
    Trinomial operator+(Trinomial x);
    Trinomial operator-(Trinomial x);
};

ostream& operator << (ostream& os, Trinomial x)
{
    os << x.a << "x^2 ";
    if(x.b < 0){
        os << x.b << "x ";
    } else {
        os << "+ " << x.b << "x ";
    }
    if(x.c < 0){
        os << x.c;
    } else {
        os << "+ " << x.c << endl;
    }
}

Trinomial Trinomial::operator-()
{
    Trinomial T;
    T.a = -this->a;
    T.b = -this->b;
    T.c = -this->c;
    return T;
}

Trinomial Trinomial::operator+(Trinomial x)
{
    Trinomial T;
    T.a = this->a + x.a;
    T.b = this->b + x.b;
    T.c = this->c + x.c;
    return T;
}

Trinomial Trinomial::operator-(Trinomial x)
{
    Trinomial T;
    T.a = this->a - x.a;
    T.b = this->b - x.b;
    T.c = this->c - x.c;
    return T;
}
int main()
{
    Trinomial a(-1, -2, 4);
    Trinomial b(1, -3, 4);
    Trinomial x, y, c, d;
    x = -a;
    y = -b;
    cout << "Trinomial A after changer: " << x << endl;
    cout << "Trinomial B after change: " << y << endl;

    c = x + y;
    d = x - y;

    cout << "Sum trinomial: " << c << endl;
    cout << "Sub trinomial: " << d << endl;
    return 0;










}
