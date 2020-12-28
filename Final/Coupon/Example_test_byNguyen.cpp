#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Phieu
{
private:
    char maPhieu[30];
    char ngayNhap[30];
    int soLuongSach;
public:
    friend class PhieuNhapSach;

};

class SachNhap
{
private:
    char tenSach[30];
    char tenTacGia[30];
    char tenNXB[30];
    int soLuong;
public:
    friend class PhieuNhapSach;


};

class PhieuNhapSach
{
private:
    Phieu phieu;
    SachNhap *a;
    int n;
public:
    void Nhap();
    void Xuat();
};

void PhieuNhapSach::Nhap()
{
    cout << "Nhap thong tin phieu: " << endl;
    cout << "\tMa phieu: ";                 fflush(stdin);      gets(phieu.maPhieu);
    cout << "\tNgay nhap: ";                fflush(stdin);      gets(phieu.ngayNhap);
    cout << "\tSo luong sach: ";            cin >> phieu.soLuongSach;
    cout << "Nhap so luong sach: ";         cin >> n;
    a = new SachNhap[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin sach " << i+1 << ": " << endl;
        cout << "\tTen sach: ";             fflush(stdin);      gets(a[i].tenSach);
        cout << "\tTen tac gia: ";          fflush(stdin);      gets(a[i].tenTacGia);
        cout << "\tTen NXB: ";              fflush(stdin);      gets(a[i].tenNXB);
        cout << "\tSo luong: ";             cin >> a[i].soLuong;
    }
}



int main()
{



}
