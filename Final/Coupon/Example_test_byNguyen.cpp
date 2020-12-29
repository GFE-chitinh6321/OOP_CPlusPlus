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

void TieuDe()
{
    cout << setw(20) << "Ten sach";
    cout << setw(20) << "Tac gia";
    cout << setw(20) << "NXB";
    cout << setw(20) << "So luong" << endl;

}

void PhieuNhapSach::Xuat()
{
    cout << "-----------------------------------------" << endl;
    cout << setw(45) << "PHIEU NHAP SACH" << endl;
    cout << setw(25) << "Ma phieu: " << phieu.maPhieu;
    cout << setw(25) << "Ngay nhap: " << phieu.ngayNhap << endl;
    cout << setw(25) << "So luong: " << phieu.soLuongSach << endl;
    cout << "Chi tiet: " << endl;
    TieuDe();
    for(int i=0; i<n; i++){
        cout << setw(20) << a[i].tenSach;
        cout << setw(20) << a[i].tenTacGia;
        cout << setw(20) << a[i].tenNXB;
        cout << setw(20) << a[i].soLuong << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void NhapNhieuPhieu(PhieuNhapSach *x, int n)
{
    for(int i=0; i<n; i++){

    }
}


int main()
{
    PhieuNhapSach a;
    a.Nhap();
    a.Xuat();


}
