#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class String
{
private:
    string str;
public:
    String operator+(String x);
    void operator=(String x);
    bool operator>(String x);
    bool operator<(String x);
    bool operator==(String x);
    friend istream& operator >> (istream& is, String &x);
    friend ostream& operator << (ostream& os, String x);
};

istream& operator >> (istream& is, String &x)
{
    cout << "Enter string: ";       fflush(stdin);
    getline(is, x.str);
    return is;
}

ostream& operator << (ostream& os, String x)
{
    os << x.str;
    return os;
}

String String::operator+(String x)
{
    String temp;
    temp.str = str + x.str;
    return temp;
}

void String::operator=(String x)
{
    str = x.str;
}

bool String::operator>(String x)
{
    if(str > x.str){
        return true;
    } else {
        return false;
    }
}

bool String :: operator<(String x)
{
    if(str < x.str){
        return true;
    } else {
        return false;
    }
}

bool String :: operator==(String x)
{
    if(str == x.str){
        return true;
    } else {
        return false;
    }
}

int main()
{
    String a, b;
    cin >> a;
    cin >> b;
    cout << "String a: " << a << endl;
    cout << "String b: " << b << endl;
    String c, d;
    c = a+b;
    cout << "Two strings after add: " << c << endl;
    d = c;
    cout << "String d = c: " << d << endl;
    cout << "Result compare a > b: ";
    if(a>b){
        cout << "True" << endl;
    } else {
        cout << "a != b" << endl;
    }

    cout << "Result compare a < b: ";
    if(a<b){
        cout << "True" << endl;
    } else {
        cout << "a != b" << endl;
    }

    cout << "Result compare a == b: ";
    if(a==b){
        cout << "True" << endl;
    } else {
        cout << "a != b" << endl;
    }




}
