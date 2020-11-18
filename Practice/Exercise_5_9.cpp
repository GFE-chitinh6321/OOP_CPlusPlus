#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
using namespace std;

class Product
{
protected:
    char nameProduct[30];
    int yearManufacture;
    float price;
public:
    void Input();
    void Output();
};

class Bill : public Product
{
private:
    int amoutSell;
    float priceSell;
public:
    void Input();
    void Output();
    friend float SumPrice(Bill a);
    friend float Interest(Bill a);
};

void Product::Input()
{
    cout << "\tEnter name product: ";               fflush(stdin);          gets(nameProduct);
    cout << "\tEnter year of manufacture: ";        cin >> yearManufacture;
    cout << "\tEnter price: ";                      cin >> price;
}

void Product::Output()
{
    cout << setw(15) << nameProduct;
    cout << setw(15) << yearManufacture;
    cout << setw(15) << price;
}

void Bill :: Input()
{
    Product::Input();
    cout << "\tEnter amount sell: ";                cin >> amoutSell;
    cout << "\tEnter price sell: ";                 cin >> priceSell;
}

void Bill::Output()
{
    Product::Output();
    cout << setw(15) << amoutSell;
    cout << setw(15) << priceSell;
}

void Title()
{
    cout << setw(15) << "STT";
    cout << setw(15) << "Product";
    cout << setw(15) << "Year";
    cout << setw(15) << "Price";
    cout << setw(15) << "Amount";
    cout << setw(15) << "Price Sell";
    cout << setw(15) << "Sum Price";
    cout << setw(15) << "Tax";
    cout << setw(15) << "Interest" << endl;

}

float SumPrice(Bill a)
{
    float sumPrice = 0;
    sumPrice = a.amoutSell * a.priceSell;
    return sumPrice;
}

float Tax(Bill a)
{
    float tax = 0;
    tax = SumPrice(a) * 0.1;
    return tax;
}

float Interest(Bill a)
{
    float interest = 0;
    interest = (a.priceSell - a.price) * a.amoutSell;
    return interest;
}

void InputListBill(Bill a[], int n)
{
    for(int i=0; i<n; i++){
        cout << "Enter information of bill " << i+1 << ": " << endl;
        a[i].Input();
    }
}

void OutputBill(Bill a, int i)
{
    cout << setw(15) << i+1;
    a.Output();
    cout << setw(15) << SumPrice(a);
    cout << setw(15) << Tax(a);
    cout << setw(15) << Interest(a) << endl;
}
void OutputListBill(Bill a[], int n)
{
    Title();
    for(int i=0; i<n; i++){
        cout << setw(15) << i+1;
        a[i].Output();
        cout << setw(15) << SumPrice(a[i]);
        cout << setw(15) << Tax(a[i]);
        cout << setw(15) << Interest(a[i]) << endl;
    }
}

void SortListByInterest(Bill a[], int n)
{
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(Interest(a[i]) > Interest(a[j])){
                Bill temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Earnings(Bill a[], int n)
{
    float earnings = 0;
    for(int i=0; i<n; i++){
        earnings += SumPrice(a[i]);
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Earnigs: " << earnings << endl;
}

void ShowBillHasMaxTax(Bill a[], int n)
{
    float maxTax = Tax(a[0]);
    for(int i=1; i<n; i++){
        if(maxTax < Tax(a[i]))
            maxTax = Tax(a[i]);
    }
    cout << "--------------------------------------------------" << endl;
    cout << "LIST BILL HAS MAX TAX" << endl;
    Title();
    for(int i=0; i<n; i++){
        if(Tax(a[i]) == maxTax){
            OutputBill(a[i], i);
        }

    }
}

int main()
{
    int n;
    cout << "Enter amount of bill: ";       cin >> n;
    Bill *a;
    a = new Bill[n];
    InputListBill(a, n);
    SortListByInterest(a, n);
    cout << "--------------------------------------------------" << endl;
    cout << "LIST BILL AFTER SORT" << endl;
    OutputListBill(a, n);
    Earnings(a, n);
    ShowBillHasMaxTax(a, n);
    return 0;
}
