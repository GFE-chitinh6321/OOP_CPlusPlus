#include <iostream>

using namespace std;

class ComplexNumber{
private:
    float Real, Virtual;

public:
    ComplexNumber(float x=0, float y=0){
        Real = x;
        Virtual = y;
    }
    friend ostream& operator << (ostream& output, const ComplexNumber &complexNumber);
    ComplexNumber operator+ (ComplexNumber &obj);
    ComplexNumber operator- (ComplexNumber &obj);
};
ostream& operator << (ostream& output, const ComplexNumber &complexNumber)
{
    output << complexNumber.Real << " + " << complexNumber.Virtual << "i" << endl;
}

ComplexNumber ComplexNumber::operator+ (ComplexNumber &obj){
    ComplexNumber sum;
    sum.Real = Real + obj.Real;
    sum.Virtual = Virtual + obj.Virtual;
    return sum;
}
ComplexNumber ComplexNumber::operator-(ComplexNumber& obj){
    ComplexNumber sub;
    sub.Real = Real - obj.Real;
    sub.Virtual = Virtual - obj.Virtual;
    return sub;
}
int main()
{
    ComplexNumber a(5, 5), b(6, 6), result;
    result = a+b;
    cout << "Sum: " << result;
    result = a-b;
    cout << "Sub: " << result;
    return 0;
}

