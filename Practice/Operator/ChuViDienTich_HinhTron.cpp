#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
public:
    float r;
    float Perimeter(){
        return 2*M_PI*r;
    }
    float Acreage(){
        return M_PI*r*r;
    }
};

int main()
{
    Circle a;
    cout << "Enter r: ";
    cin >> a.r;
    cout << "Perimeter: " << a.Perimeter() << endl;
    cout << "Acreage: " << a.Acreage() << endl;
    return 0;
}
