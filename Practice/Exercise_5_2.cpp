#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

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

int main()
{
    int n;
    cout << "Enter amount of product: ";    cin >> n;
    ElectronicProduct *a;
    a = new ElectronicProduct[n];
    for(int i=0; i<n; i++){
        cout << "Enter information product " << i+1 << ": " << endl;
        a[i].Input();
    }
    cout << "------------------------------------------------" << endl;
    cout << "LIST PRODUCT" << endl;
    Title();
    for(int i=0; i<n; i++){
        a[i].Output();
    }
    ShowProductHasMinWeight(a, n);

    return 0;
}
