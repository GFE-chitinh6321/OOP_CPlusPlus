#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int n;
    int *a;
public:
    Array(){
        this->n = 0;
        this->a = NULL;
    }
    void Input();
    void Output();
    Array operator ++ ();
    Array operator + (Array x);
    Array operator -- ();
    friend istream& operator >> (istream& is, Array &x);
    friend ostream& operator << (ostream& os, Array x);
};

istream& operator >> (istream& is, Array &x)
{
    cout << "Enter amount of elements in the array: ";
    is >> x.n;
    x.a = new int[x.n];
    for(int i=0; i<x.n; i++){
        cout << "\ta[" << i << "] = ";
        is >> x.a[i];
    }
    return is;
}

ostream& operator << (ostream& os, Array x)
{
    for(int i=0; i<x.n; i++){
        os << x.a[i] << "  ";
    }
    return os;
}

void Array::Input()
{
    cout << "Enter amount of elements in the array: ";
    cin >> n;
    a = new int[n];
    for(int i=0; i<n; i++){
        cout << "\ta[" << i << "] = ";
        cin >> a[i];
    }
}

void Array::Output()
{
    for(int i=0; i<n; i++){
        cout << a[i] << "  ";
    }
}

int MinEvenNumber(int a[], int n)
{
    int minEvenNumber = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0){
            count++;
            minEvenNumber = a[i];
        }
    }
    for(int i=0; i<n; i++){
        if(a[i]%2 == 0 && a[i]<minEvenNumber)
            minEvenNumber = a[i];
    }
    if(count == 0)
        return 2;
    return minEvenNumber;
}

Array Array::operator++()
{
    int bonusEvenNumber = MinEvenNumber(this->a, this->n);
    for(int i=0; i<n; i++){
        a[i] += bonusEvenNumber;
    }
}

Array Array::operator+(Array x)
{
    Array sum;
    if(this->n != x.n){
        return Array();
    } else {
        sum.n = this->n;
        sum.a = new int[sum.n];
        for(int i=0; i<sum.n; i++){
            sum.a[i] = this->a[i] + x.a[i];
        }
        return sum;
    }
}

Array Array::operator--()
{
    for(int i=0; i<this->n; i++){
        for(int j=i; j<this->n; j++){
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
    Array a, b, z;
    cout << "Enter array a: " << endl;
    cin >> a;
    cout << "Enter array b: " << endl;
    cin >> b;
    cout << "Enter array c: " << endl;
    z.Input();
    cout << "----------------------------------------------------" << endl;
    cout << "Array a: " << a << endl;
    cout << "Array b: " << b << endl;
    cout << "Array c: ";;
    z.Output();
    ++a;
    cout << endl << "Array a after bonus min even number: " << a << endl;
    Array c;
    c = a+b;
    cout << "Result sum array a & b: " << c << endl;
    --b;
    cout << "Array b after soft: " << b << endl;

    return 0;
}
