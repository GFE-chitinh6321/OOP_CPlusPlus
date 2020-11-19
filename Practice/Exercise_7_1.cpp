#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    void Input();
    void Output();
    friend class Television;
};

class Company
{
private:
    char nameCompany[30];
    char address[30];
public:
    void Input();
    void Output();
    friend class Product;
    friend class Television;
};

class Product
{
protected:
    char product[30];
    Company x;
    int price;
public:
    void Input();
    void Output();
    Product(){
        strcpy(product, "Omo");
        strcpy(x.nameCompany, "GFE-ChiTinh");
        strcpy(x.address, "Ha Nam");
        price = 150000;
    }
};

class Television : public Product
{
private:
    int size;
    Date date;
public:
    void Input();
    void Output();
    Television(){
        strcpy(product, "Tivi Sony");
        strcpy(x.nameCompany, "Sony");
        strcpy(x.address, "Ha Noi");
        price = 250000;
        size = 50;
        date.day = 6;
        date.month = 3;
        date.year = 2019;
    }
};

void Television::Output()
{
    cout << setw(15) << product;
    cout << setw(15) << x.nameCompany;
    cout << setw(15) << x.address;
    cout << setw(15) << price;
    cout << setw(15) << size;
    cout << setw(15) << date.day;
    cout << setw(15) << date.month;
    cout << setw(15) << date.year;
}















int main()
{
    Television a;
    a.Output();

}
