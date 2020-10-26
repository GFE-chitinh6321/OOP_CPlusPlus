#include <iostream>

using namespace std;


class Vector{
private:
    int x, y;
public:
    void input();
    void output();
    Vector operator+ (Vector a);
    Vector operator- (Vector b);
};

void Vector::input(){
    cout << "\tx = ";       cin >> x;
    cout << "\ty = ";       cin >> y;
}
void Vector::output(){
    cout << "(" << x << ", " << y << ")" << endl;
}
Vector Vector::operator+(Vector a){
    Vector sum;
    sum.x = x + a.x;
    sum.y = y + a.y;
    return sum;
}
Vector Vector::operator-(Vector a){
    Vector sub;
    sub.x = x - a.x;
    sub.y = y - a.y;
    return sub;
}

int main()
{
    Vector a, b;
    cout << "Enter vector a: " << endl;
    a.input();
    cout << "Enter vector b: " << endl;
    b.input();

    Vector c = a + b;
    cout << "Sum = ";       c.output();
    Vector d = a - b;
    cout << "Sub = ";       d.output();
    return 0;
}
















