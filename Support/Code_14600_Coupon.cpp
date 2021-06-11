#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Phieu {
private:
    char ngayLap[30];
    char nguoiLap[30];
    char maDonVi[30];
    char tenDonVi[30];
    char diaChiDonVi[30];
    char truongDonVi[30];
public:
    friend class PhieuThongKeTaiSan;
};

class TaiSan {
private:
    char maTaiSan[30];
    char tenTaiSan[30];
    char donViTinh[30];
    int giaTri;
public:
    friend class PhieuThongKeTaiSan;
};

class PhieuThongKeTaiSan {
private:
    Phieu phieu;
    TaiSan *taiSan;
    int n;
public:
    void Nhap();
    void Xuat();
};

void PhieuThongKeTaiSan::Nhap(){
    cout << "Nhap thong tin phieu: " << endl;
    cout << "\tNgay lap: ";                 fflush(stdin);      gets(phieu.ngayLap);
    cout << "\tNguoi lap: ";                fflush(stdin);      gets(phieu.nguoiLap);
    cout << "\tMa don vi: ";                fflush(stdin);      gets(phieu.maDonVi);
    cout << "\tTen don vi: ";               fflush(stdin);      gets(phieu.tenDonVi);
    cout << "\tDia chi don vi: ";           fflush(stdin);      gets(phieu.diaChiDonVi);
    cout << "\tTruong don vi: ";            fflush(stdin);      gets(phieu.truongDonVi);
    cout << "Nhap so luong tai san: ";      cin >> n;
    taiSan = new TaiSan[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin tai san " << i+1 << ": " << endl;
        cout << "\tMa tai san: ";            fflush(stdin);      gets(taiSan[i].maTaiSan);
        cout << "\tTen tai san: ";           fflush(stdin);      gets(taiSan[i].tenTaiSan);
        cout << "\tDon vi tinh: ";           fflush(stdin);      gets(taiSan[i].donViTinh);
        cout << "\tGia tri: ";               cin >> taiSan[i].giaTri;
    }
}

void TieuDeBangThietBi() {
    cout << setw(20) << "Ma tai san";
    cout << setw(20) << "Ten tai san";
    cout << setw(20) << "Don vi tinh";
    cout << setw(20) << "Gia tri" << endl;
}

void PhieuThongKeTaiSan::Xuat() {
    cout << "------------------------------------------------------" << endl;
    cout << "TONG CONG TY ABC" << endl;
    cout << setw(50) << "BANG THONG KE TAI SAN" << endl;
    cout << setw(20) << left << "Ngay lap: ";
    cout << setw(20) << phieu.ngayLap;
    cout << setw(20) << "Nguoi lap: ";
    cout << setw(20) << phieu.nguoiLap << endl;
    cout << setw(20) << left << "Ma don vi: ";
    cout << setw(20) << phieu.maDonVi;
    cout << setw(20) << "Ten don vi: ";
    cout << setw(20) << phieu.tenDonVi << endl;
    cout << setw(20) << left << "Dia chi don vi: ";
    cout << setw(20) << phieu.diaChiDonVi;
    cout << setw(20) << "Truong don vi: ";
    cout << setw(20) << phieu.truongDonVi << endl;
    cout << setw(20) << left << "CHI TIET" << endl;
    cout << "------------------------------------------------------" << endl;
    TieuDeBangThietBi();
    cout << "------------------------------------------------------" << endl;
    int tongSoLuongThietBi = 0;
    for (int i=0; i<n; i++){
        cout << setw(20) << taiSan[i].maTaiSan;
        cout << setw(20) << taiSan[i].tenTaiSan;
        cout << setw(20) << taiSan[i].donViTinh;
        cout << setw(20) << taiSan[i].giaTri << endl;
        tongSoLuongThietBi += taiSan[i].giaTri;
    }
    cout << "------------------------------------------------------" << endl;
    cout << setw(30) << "Tong so luong thiet bi: ";
    cout << setw(50) << tongSoLuongThietBi << endl;
    cout << setw(20) << "Giam doc";
    cout << setw(20) << "Phong quan ly";
    cout << setw(20) << "Nguoi lap" << endl;
}


int main()
{
    PhieuThongKeTaiSan phieuThongKeTaiSan;
    phieuThongKeTaiSan.Nhap();
    phieuThongKeTaiSan.Xuat();
    return 0;


}
