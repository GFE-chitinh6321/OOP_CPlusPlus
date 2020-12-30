#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class PhieuNhapSach;

class Phieu
{
private:
    char maPhieu[30];
    char ngayNhap[30];
    int soLuongSach;
public:
    friend class PhieuNhapSach;
    friend void XuatThongTinSachNhapNhieuNhat(PhieuNhapSach *x, int p);

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
    friend int SoLuongSachMaxTrenPhieu(PhieuNhapSach p);
    friend void XuatThongTinSachNhapNhieuNhat(PhieuNhapSach *x, int p);

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
    friend int SoLuongSachMaxTrenPhieu(PhieuNhapSach p);
    friend void XuatThongTinSachNhapNhieuNhat(PhieuNhapSach *x, int p);
};

void PhieuNhapSach::Nhap()
{
//    cout << "Nhap thong tin phieu: " << endl;
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

void NhapNhieuPhieu(PhieuNhapSach *x, int p)
{
    for(int i=0; i<p; i++){
        cout << "Nhap thong tin phieu " << i+1 << ": " << endl;
        x[i].Nhap();
    }
}

void XuatNhieuPhieu(PhieuNhapSach *x, int p)
{
    for(int i=0; i<p; i++){
        cout << "PHIEU " << i+1 << ": " << endl;
        x[i].Xuat();
    }

}

int SoLuongSachMaxTrenPhieu(PhieuNhapSach p)
{
    int max = 0;
    for(int i=0; i<p.n; i++){
        if(max < p.a[i].soLuong)
            max = p.a[i].soLuong;
    }
    return max;
}

void XuatThongTinSachNhapNhieuNhat(PhieuNhapSach *x, int p)
{
    cout << "THONG TIN SACH CO SO LUONG NHIEU NHAT MOI PHIEU" << endl;
    cout << setw(20) << "Ma phieu";
    TieuDe();
    for(int i=0; i<p; i++){
        for(int j=0; j<x[i].n; j++){
            if(x[i].a[j].soLuong == SoLuongSachMaxTrenPhieu(x[i]))
            {
                cout << setw(20) << x[i].phieu.maPhieu;
                cout << setw(20) << x[i].a[j].tenSach;
                cout << setw(20) << x[i].a[j].tenTacGia;
                cout << setw(20) << x[i].a[j].tenNXB;
                cout << setw(20) << x[i].a[j].soLuong << endl;
            }
        }
    }
}

int main()
{
    PhieuNhapSach *x;
    int p;
    cout << "Nhap so luong phieu: ";        cin >> p;
    x = new PhieuNhapSach[p];
    NhapNhieuPhieu(x, p);
    XuatNhieuPhieu(x, p);
    XuatThongTinSachNhapNhieuNhat(x, p);
    return 0;
}
