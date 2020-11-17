#include <iostream>

using namespace std;

class Matrix
{
private:
    int m, n;
    double **a;
public:
    Matrix operator-();
    Matrix operator+(Matrix x);
    Matrix operator-(Matrix x);
    friend istream& operator >> (istream& is, Matrix &x);
    friend ostream& operator << (ostream& os, Matrix x);
};

istream& operator >> (istream& is, Matrix &x)
{
    cout << "\tEnter amount of row: ";
    is >> x.m;
    cout << "\tEnter amount of column: ";
    is >> x.n;

    x.a = new double*[x.m];
    for(int i=0; i<x.m; i++){
        x.a[i] = new double[x.n];
    }
    for(int i=0; i<x.m; i++){
        for(int j=0; j<x.n; j++){
            cout << "a[" << i << "][" << j << "] = ";
            is >> x.a[i][j];
        }
    }
    return is;
}

ostream& operator << (ostream& os, Matrix x)
{
    for(int i=0; i<x.m; i++){
        for(int j=0; j<x.n; j++){
            os << x.a[i][j] << "  ";
        }
        os << endl;
    }
    return os;
}

Matrix Matrix ::operator-()
{
    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            this->a[i][j] = -this->a[i][i];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix x)
{
    Matrix z;
    if(this->m != x.m && this->n != x.n){
        return *this;
    }
    z.m = x.m;
    z.n = x.n;
    z.a = new double*[z.m];
    for(int i=0; i<z.m; i++){
        z.a[i] = new double[z.n];
    }
    for(int i=0; i<z.m; i++){
        for(int j=0; j<z.n; j++){
            z.a[i][j] = this->a[i][j] + x.a[i][j];
        }
    }
    return z;
}

Matrix Matrix::operator-(Matrix x)
{
    Matrix z;
    if(this->m != x.m && this->n != x.n){
        return *this;
    }
    z.m = x.m;
    z.n = x.n;
    z.a = new double*[z.m];
    for(int i=0; i<z.m; i++){
        z.a[i] = new double[z.n];
    }
    for(int i=0; i<z.m; i++){
        for(int j=0; j<z.n; j++){
            z.a[i][j] = this->a[i][j] - x.a[i][j];
        }
    }
    return z;
}

int main()
{
    Matrix X, Y, mtx01, mtx02, mtx03, mtx04;
    cout << "Enter matrix X: " << endl;
    cin >> X;
    cout << "Enter matrix Y: " << endl;
    cin >> Y;

    mtx01 = -X;
    mtx02 = -Y;
    cout << "Matrix X after change: " << endl;
    cout << mtx01;
    cout << "Matrix Y after change: " << endl;
    cout << mtx02;

    mtx03 = mtx01 + mtx02;
    mtx04 = mtx01 - mtx02;

    cout << "Sum matrix: " << endl;
    cout << mtx03;
    cout << "Sub matrix: " << endl;
    cout << mtx04;
    return 0;
}
