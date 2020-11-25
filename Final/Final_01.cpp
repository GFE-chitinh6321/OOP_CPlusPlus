#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
using namespace std;

class SachGK;

class NhaXuatBan
{
private:
    char tenNXB[30];
    char diaChiNXB[30];
public:
    friend class SachGK;
    friend void HienThiSGK_NXBGiaoDuc(SachGK a[], int n);
};

class TacGia
{
private:
    char tenTacGia[30];
    char diaChiTacGia[30];
public:
    friend class SachGK;
};

class IdSach
{
protected:
    char tenSach[30];
    char maSach[30];
public:
    void Nhap();
    void Xuat();
};

class SachGK : public IdSach
{
private:
    TacGia x;
    NhaXuatBan y;
public:
    void Nhap();
    void Xuat();
    friend void HienThiSGK_NXBGiaoDuc(SachGK a[], int n);
    friend void HienThiSGK_LTHDT(SachGK a[], int n);
};

void IdSach::Nhap()
{
    cout << "\tTen sach: ";               fflush(stdin);          gets(tenSach);
    cout << "\tMa sach: ";                fflush(stdin);           gets(maSach);
}

void IdSach::Xuat()
{
    cout << setw(15) << tenSach;
    cout << setw(15) << maSach;
}

void SachGK::Nhap()
{
    IdSach::Nhap();
    cout << "\tTac gia: ";                 fflush(stdin);           gets(x.tenTacGia);
    cout << "\tDia chi tac gia: ";         fflush(stdin);           gets(x.diaChiTacGia);
    cout << "\tNha xuat ban: ";            fflush(stdin);           gets(y.tenNXB);
    cout << "\tDia chi nha xuat ban: ";    fflush(stdin);           gets(y.diaChiNXB);

}

void SachGK::Xuat()
{
    IdSach::Xuat();
    cout << setw(15) << x.tenTacGia;
    cout << setw(15) << x.diaChiTacGia;
    cout << setw(15) << y.tenNXB;
    cout << setw(15) << y.diaChiNXB << endl;
}

void NhapDanhSachSGK(SachGK a[], int n)
{
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin SGK " << i+1 << ": " << endl;
        a[i].Nhap();
    }
}

void HienThiDanhSachSGK(SachGK a[], int n)
{
    for(int i=0; i<n; i++){
        a[i].Xuat();
    }
}

void TieuDe()
{
    cout << setw(15) << "Ten sach";
    cout << setw(15) << "Ma sach";
    cout << setw(15) << "Tac gia";
    cout << setw(15) << "DC TG";
    cout << setw(15) << "NXB";
    cout << setw(15) << "DC NXB" << endl;
}

void HienThiSGK_NXBGiaoDuc(SachGK a[], int n)
{
    cout << "---------------------------------------------------------" << endl;
    cout << "DANH SACH SGK NXB GIAO DUC" << endl;
    for(int i=0; i<n; i++){
        if(strcmp(a[i].y.tenNXB, "Giao Duc") == 0){
            a[i].Xuat();
        }
    }
}

void HienThiSGK_LTHDT(SachGK a[], int n)
{
    cout << "---------------------------------------------------------" << endl;
    cout << "DANH SACH SGK LTHDT" << endl;
    for(int i=0; i<n; i++){
        if(strcmp(a[i].tenSach, "LTHDT") == 0){
            a[i].Xuat();
        }
    }
}

void ThemSachVaoViTriK(SachGK a[], int &n, int k)
{
    SachGK sachThem;
    a = (SachGK*) realloc(a, n+1);
    cout << "Nhap thong tin sach can them: " << endl;
    sachThem.Nhap();
    for(int i=n-1; i>=k-1; i--){
        a[i+1] = a[i];
    }
    a[k-1] = sachThem;
    n++;
}

int main()
{
    int n;
    SachGK *a;
    cout << "Nhap so luong sach giao khoa: ";   cin >> n;
    a = new SachGK[n];
    NhapDanhSachSGK(a, n);
    cout << "---------------------------------------------------------" << endl;
    cout << "DANH SACH SGK" << endl;
    TieuDe();
    HienThiDanhSachSGK(a, n);
    HienThiSGK_NXBGiaoDuc(a, n);
    HienThiSGK_LTHDT(a, n);
    cout << "---------------------------------------------------------" << endl;
    int k;
    cout << "Nhap vi tri can them sach: ";  cin >> k;
    ThemSachVaoViTriK(a, n, k);
    cout << "---------------------------------------------------------" << endl;
    cout << "DANH SACH SGK SAU KHI CHEN THEM SACH" << endl;
    TieuDe();
    HienThiDanhSachSGK(a, n);

    return 0;
}
