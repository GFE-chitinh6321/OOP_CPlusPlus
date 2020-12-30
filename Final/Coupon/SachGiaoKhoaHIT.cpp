#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
using namespace std;

class SachGiaoKhoa;

class TacGia
{
private:
    char tenTacGia[30];
    char diaChiTacGia[30];
public:
    friend class SachGiaoKhoa;

};

class NhaXuatBan
{
private:
    char tenNXB[30];
    char diaChiNXB[30];
public:
    friend class SachGiaoKhoa;
    friend void XuatSGKCuaNXBGiaoDuc(SachGiaoKhoa *a, int n);

};

class IDSach
{
protected:
    char tenSach[30];
    char maSach[30];
public:
    void Nhap();
    void Xuat();
};

class SachGiaoKhoa : public IDSach
{
private:
    TacGia x;
    NhaXuatBan y;
public:
    void Nhap();
    void Xuat();
    friend void XuatSGKCuaNXBGiaoDuc(SachGiaoKhoa *a, int n);
    friend void XuatSGKTenLTHDT(SachGiaoKhoa *a, int n);
};

void IDSach :: Nhap()
{
    cout << "\tTen sach: ";                  fflush(stdin);         gets(tenSach);
    cout << "\tMa sach: ";                   fflush(stdin);         gets(maSach);
}

void IDSach :: Xuat()
{
    cout << setw(15) << maSach;
    cout << setw(15) << tenSach;
}

void TieuDe()
{
    cout << setw(15) << "Ma sach";
    cout << setw(15) << "Ten sach";
    cout << setw(15) << "Tac gia";
    cout << setw(15) << "Dia chi TG";
    cout << setw(15) << "NXB";
    cout << setw(15) << "Dia chi NXB" << endl;
}

void SachGiaoKhoa::Nhap()
{
    IDSach::Nhap();
    cout << "\tTac gia: ";                  fflush(stdin);          gets(x.tenTacGia);
    cout << "\tDia chi: ";                  fflush(stdin);          gets(x.diaChiTacGia);
    cout << "\tNha xuat ban: ";             fflush(stdin);          gets(y.tenNXB);
    cout << "\tDia chi NXB: ";              fflush(stdin);          gets(y.diaChiNXB);
}

void SachGiaoKhoa::Xuat()
{
    IDSach::Xuat();
    cout << setw(15) << x.tenTacGia;
    cout << setw(15) << x.diaChiTacGia;
    cout << setw(15) << y.tenNXB;
    cout << setw(15) << y.diaChiNXB << endl;
}

void NhapNhieuSachGiaoKhoa(SachGiaoKhoa *a, int n)
{
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin sach " << i+1 << ": " << endl;
        a[i].Nhap();
    }
}

void XuatNhieuSachGiaoKhoa(SachGiaoKhoa *a, int n)
{
    cout << "-----------------------------------------------" << endl;
    cout << "LIST SACH:" << endl;
    TieuDe();
    for(int i=0; i<n; i++){
        a[i].Xuat();
    }
    cout << "-----------------------------------------------" << endl;
}

void XuatSGKCuaNXBGiaoDuc(SachGiaoKhoa *a, int n)
{
    cout << "-----------------------------------------------" << endl;
    cout << "SGK NXB GIAO DUC: " << endl;
    TieuDe();
    for(int i=0; i<n; i++){
        if(strcmp(a[i].y.tenNXB, "Giao Duc") == 0){
            a[i].Xuat();
        }
    }
}

void XuatSGKTenLTHDT(SachGiaoKhoa *a, int n)
{
    cout << "-----------------------------------------------" << endl;
    cout << "SGK LTHDT: " << endl;
    TieuDe();
    for(int i=0; i<n; i++){
        if(strcmp(a[i].tenSach, "LTHDT") == 0){
            a[i].Xuat();
        }
    }
}

void ChenSGK(SachGiaoKhoa *a, int &n, int k)
{

    a = (SachGiaoKhoa *)realloc(a, n+1);
    SachGiaoKhoa newBook;
    cout << "Nhap thong tin SGK can them: " << endl;
    newBook.Nhap();
    for(int i=n-1; i>=k-1; i--){
        a[i+1] = a[i];
    }
    a[k-1] = newBook;
    n++;
}

int main()
{
    SachGiaoKhoa *a;
    int n;
    cout << "Nhap so luong sach: ";     cin >> n;
    a = new SachGiaoKhoa[n];
    NhapNhieuSachGiaoKhoa(a, n);
    XuatNhieuSachGiaoKhoa(a, n);
    XuatSGKCuaNXBGiaoDuc(a, n);
    XuatSGKTenLTHDT(a, n);
    int k;
    cout << "Nhap vi tri can chen: ";   cin >> k;
    ChenSGK(a, n, k);
    XuatNhieuSachGiaoKhoa(a, n);
    return 0;

}
