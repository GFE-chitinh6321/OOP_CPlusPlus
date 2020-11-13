#include <iostream>
#include <math.h>

using namespace std;

class Array
{
private:
    int *a;
    int n;
public:
    void operator++();
    void operator--();
    friend istream& operator >> (istream &is, Array &obj);
    friend ostream& operator << (ostream &os, Array obj);
};

istream& operator >> (istream &is, Array &obj)
{
    cout << "Enter amount of array: ";
    is >> obj.n;
    for(int i=0; i<obj.n; i++)
    {
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
    return os;
}
void Array :: operator++()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void Array :: operator--()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    Array x;
    cin >> x;
    cout << "Your array: " << x << endl;
    ++x;
    cout << "Array after sort (ascending): " << x << endl;
    --x;
    cout << "Array after sort (decrease): " << x << endl;
    return 0;
}

