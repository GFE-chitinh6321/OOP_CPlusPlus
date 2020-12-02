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
    char ngayLap[30];
    char maNCC[30];
    char tenNCC[30];
    char diaChi[30];
public:
    friend class PhieuNhapHang;
};

class HangNhap
{
private:
    char tenHang[30];
    float donGia;
    int soLuong;
    float thanhTien;
public:
    friend class PhieuNhapHang;
};

class PhieuNhapHang
{
private:
    Phieu phieu;
    HangNhap *x;
    int n;
public:
    void Nhap();
    void Xuat();
};

void PhieuNhapHang::Nhap()
{
    cout << "Nhap thong tin phieu: " << endl;
    cout << "\tMa phieu: ";                     fflush(stdin);          gets(phieu.maPhieu);
    cout << "\tNgay lap: ";                     fflush(stdin);          gets(phieu.ngayLap);
    cout << "\tMa NCC: ";                       fflush(stdin);          gets(phieu.maNCC);
    cout << "\tTen NCC: ";                      fflush(stdin);          gets(phieu.tenNCC);
    cout << "\tDia chi: ";                      fflush(stdin);          gets(phieu.diaChi);
    cout << "Nhap so luong mat hang: ";         cin >> n;
    x = new HangNhap[n];
    for(int i=0; i<n; i++){
        cout << "Thong tin mat hang " << i+1 << ": " << endl;
        cout << "\tTen hang: ";                 fflush(stdin);          gets(x[i].tenHang);
        cout << "\tDon gia: ";                  cin >> x[i].donGia;
        cout << "\tTen hang: ";                 cin >> x[i].soLuong;
        x[i].thanhTien = x[i].soLuong * x[i].donGia;
    }
}

void Title()
{
    cout << setw(15) << "Ten hang";
    cout << setw(15) << "Don gia";
    cout << setw(15) << "So luong";
    cout << setw(15) << "Thanh tien" << endl;
}

void PhieuNhapHang::Xuat()
{
    cout << "-----------------------------------------------------------" << endl;
    cout << setw(30) << "PHIEU NHAP HANG" << endl;
    cout << setw(20) << "Ma phieu: " << phieu.maPhieu;
    cout << setw(20) << "Ngay lap: " << phieu.ngayLap << endl;
    cout << setw(20) << "Ma NCC: " << phieu.maNCC;
    cout << setw(20) << "Ten NCC: " << phieu.tenNCC << endl;
    cout << setw(20) << "Dia chi: " << phieu.diaChi << endl;
    Title();
    for(int i=0; i<n; i++){
        cout << setw(15) << x[i].tenHang;
        cout << setw(15) << x[i].donGia;
        cout << setw(15) << x[i].soLuong;
        cout << setw(15) << x[i].thanhTien << endl;
    }
}

int main()
{
    PhieuNhapHang a;
    a.Nhap();
    a.Xuat();
    return 0;
}
