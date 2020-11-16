#include <iostream>

using namespace std;

class Matrix
{
private:
    int m, n;
    double **a;
public:
    Matrix operator-();
    Matrix operator+ (Matrix a);
    Matrix operator- (Matrix a);
    friend istream& operator >>(istream& is, Matrix &x);
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

Matrix Matrix::operator-()
{
    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            this->a[i][j] = -this->a[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix x)
{
    Matrix sum;
    if(this->m != x.m && this->n != x.n){
        return *this;
    }
    sum.m = x.m;
    sum.n = x.n;
    sum.a = new double*[sum.m];
    for(int i=0; i<sum.m; i++){
        sum.a[i] = new double[sum.n];
    }

    for(int i=0; i<sum.m; i++){
        for(int j=0; j<sum.n; j++){
            sum.a[i][j] = this->a[i][j] + x.a[i][j];
        }
    }
    return sum;
}

Matrix Matrix::operator-(Matrix x)
{
    Matrix sub;
    if(this->m != x.m && this->n != x.n){
        return *this;
    }
    sub.m = x.m;
    sub.n = x.n;
    sub.a = new double*[sub.m];
    for(int i=0; i<sub.m; i++){
        sub.a[i] = new double[sub.n];
    }
    for(int i=0; i<sub.m; i++){
        for(int j=0; j<sub.n; j++){
            sub.a[i][j] = this->a[i][j] - x.a[i][j];
        }
    }
    return sub;
}

int main()
{
    Matrix X, Y, matrix01, matrix02, matrix03, matrix04;
    cout << "Enter matrix X: " << endl;
    cin >> X;
    cout << "Enter matrix Y: " << endl;
    cin >> Y;

    matrix01 = -X;
    matrix02 = -Y;
    cout << "Matrix X after change: " << endl;
    cout << matrix01;
    cout << "Matrix Y after change: " << endl;
    cout << matrix02;

    matrix03 = matrix01 + matrix02;
    matrix04 = matrix01 - matrix02;
    cout << "Sum matrix: " << endl;
    cout << matrix03;
    cout << "Sub matrix: " << endl;
    cout << matrix04;
    return 0;
}
