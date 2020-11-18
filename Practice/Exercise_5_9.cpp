#include <iostream>

using namespace std;

class Product
{
protected:
    char nameProduct[30];
    int yearManufacture;
    int price;
public:
    void Input();
    void Output();
};

class Bill : public Product
{

};


int main()
{

}
