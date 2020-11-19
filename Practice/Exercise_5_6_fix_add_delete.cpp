#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Product
{
protected:
    char codeProduct[30];
    char nameProduct[30];
    char dateManufacture[30];
    int weight;
    char color[30];
public:
    void Input();
    void Output();
};

class ElectronicProduct : public Product
{
private:
    int wattage;
    int electric;
public:
    void Input();
    void Output();
    friend void ShowProductHasMinWeight(ElectronicProduct a[], int n);
};

void Product :: Input()
{
    cout << "\tEnter code product: ";           fflush(stdin);          gets(codeProduct);
    cout << "\tEnter name product: ";           fflush(stdin);          gets(nameProduct);
    cout << "\tEnter date of manufacture: ";    fflush(stdin);          gets(dateManufacture);
    cout << "\tEnter weight product: ";         cin >> weight;
    cout << "\tEnter color product: ";          fflush(stdin);          gets(color);
}

void Product :: Output()
{
    cout << setw(15) << codeProduct;
    cout << setw(15) << nameProduct;
    cout << setw(15) << dateManufacture;
    cout << setw(15) << weight;
    cout << setw(15) << color;
}

void ElectronicProduct::Input()
{
    Product::Input();
    cout << "\tEnter wattage: ";            cin >> wattage;
    cout << "\tEnter electric: ";           cin >> electric;
}

void ElectronicProduct :: Output()
{
    Product::Output();
    cout << setw(15) << wattage;
    cout << setw(15) << electric << endl;
}

void Title()
{
    cout << setw(15) << "Code";
    cout << setw(15) << "Product";
    cout << setw(15) << "Date";
    cout << setw(15) << "Weight";
    cout << setw(15) << "Color";
    cout << setw(15) << "Wattge";
    cout << setw(15) << "Electric" << endl;
}

void InputListProduct(ElectronicProduct a[], int n)
{
    for(int i=0; i<n; i++){
        cout << "Enter information product " << i+1 << ": " << endl;
        a[i].Input();
    }
}

void ShowListProduct(ElectronicProduct a[], int n)
{
    for(int i=0; i<n; i++){
        a[i].Output();
    }
}

void ShowProductHasMinWeight(ElectronicProduct a[], int n)
{
    int minWeight = a[0].weight;
    for(int i=1; i<n; i++){
        if(minWeight > a[i].weight)
            minWeight = a[i].weight;
    }
    cout << "------------------------------------------------" << endl;
    cout << "LIST PRODUCT HAS MIN WEIGHT" << endl;
    Title();
    for(int i=0; i<n; i++){
        if(a[i].weight == minWeight)
            a[i].Output();
    }
}

void AddProductIntoList(ElectronicProduct a[], int &n, int k)
{
    a = (ElectronicProduct *) realloc(a, n + 1);
    ElectronicProduct addProduct;
    cout << "Enter information of product you need add: " << endl;
    addProduct.Input();
    for(int i=n-1; i>=k-1; i--){
        a[i+1] = a[i];
    }
    a[k-1] = addProduct;
    n++;
}

void DeleteProductFromList(ElectronicProduct a[], int &n)
{
    int x;
    cout << "Enter location you need delete product: ";
    cin >> x;
    for(int i=x-1; i<n; i++){
        a[i] = a[i+1];
    }
    n--;
}
int main()
{
    int n;
    cout << "Enter amount of product: ";    cin >> n;
    ElectronicProduct *a;
    a = new ElectronicProduct[n];

    InputListProduct(a, n);
    cout << "------------------------------------------------" << endl;
    cout << "LIST PRODUCT" << endl;
    Title();
    ShowListProduct(a, n);

    ShowProductHasMinWeight(a, n);

    int k;
    cout << "Enter location you need add product: ";
    cin >> k;
    AddProductIntoList(a, n, k);
    cout << "------------------------------------------------" << endl;
    cout << "LIST PRODUCT AFTER ADD" << endl;
    ShowListProduct(a, n);

    DeleteProductFromList(a, n);
    cout << "------------------------------------------------" << endl;
    cout << "LIST PRODUCT AFTER DELETE" << endl;
    ShowListProduct(a, n);

    return 0;
}
