#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class PhieuThongKeThietBi;

class Phieu {
private:
    char ngayLap[30];
    char nguoiLap[30];
    char maPhongmay[30];
    char tenPhong[30];
    char tenNguoiQuanLy[30];
public:
    friend class PhieuThongKeThietBi;

};

class ThietBi {
private:
    char maThietBi[30];
    char tenThietBi[30];
    char tinhTrang[30];
    int soLuong;
public:
    friend class PhieuThongKeThietBi;
};

class PhieuThongKeThietBi {
private:
    Phieu phieu;
    ThietBi *thietBi;
    int soLuongThietBi;
public:
    void Nhap();
    void Xuat();

};

void PhieuThongKeThietBi::Nhap() {
    cout << "Nhap thong tin phieu" << endl;
    cout << "\tNgay lap: ";              fflush(stdin);      gets(phieu.ngayLap);
    cout << "\tNguoi lap: ";             fflush(stdin);      gets(phieu.nguoiLap);
    cout << "\tMa phong may: ";         fflush(stdin);      gets(phieu.maPhongmay);
    cout << "\tTen phong: ";            fflush(stdin);      gets(phieu.tenPhong);
    cout << "\tTen nguoi quan ly: ";    fflush(stdin);      gets(phieu.tenNguoiQuanLy);
    cout << "So luong thiet bi: ";      cin >> soLuongThietBi;
    thietBi = new ThietBi[soLuongThietBi];
    for (int i=0; i<soLuongThietBi; i++){
        cout << "Nhap thong tin thiet bi " << i+1 << ":" << endl;
        cout << "\tMa thiet bi: ";          fflush(stdin);      gets(thietBi[i].maThietBi);
        cout << "\tTen thiet bi: ";          fflush(stdin);      gets(thietBi[i].tenThietBi);
        cout << "\tTinh trang: ";           fflush(stdin);      gets(thietBi[i].tinhTrang);
        cout << "\tSo luong: ";             cin >> thietBi[i].soLuong;
    }
}

void TieuDeThietBi(){
    cout << setw(20) << "Ma thiet bi";
    cout << setw(20) << "Ten thiet bi";
    cout << setw(20) << "Tinh trang";
    cout << setw(20) << "So luong" << endl;
}

void PhieuThongKeThietBi::Xuat() {
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "TRUONG DHCNHN" << endl;
    cout << setw(40) << "BANG THONG KE THIET BI" << endl;
    cout << setw(20) << left << "Ngay lap: ";
    cout << setw(20) << phieu.ngayLap;
    cout << setw(20) << "Nguoi lap: ";
    cout << setw(20) << phieu.nguoiLap << endl;
    cout << setw(20) << left << "Ma phong may: ";
    cout << setw(20) << phieu.maPhongmay;
    cout << setw(20) << "ten phong: ";
    cout << setw(20) << phieu.tenPhong << endl;
    cout << setw(20) << left << "Ten nguoi quan ly: ";
    cout << setw(20) << phieu.tenNguoiQuanLy << endl;
    cout << "Chi tiet" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    TieuDeThietBi();
    int tongSoLuongThietBi = 0;
    for (int i=0; i<soLuongThietBi; i++){
        cout << setw(20) << thietBi[i].maThietBi;
        cout << setw(20) << thietBi[i].tenThietBi;
        cout << setw(20) << thietBi[i].tinhTrang;
        cout << setw(20) << thietBi[i].soLuong << endl;
        tongSoLuongThietBi += thietBi[i].soLuong;
    }
    cout << setw(30) << "Tong so luong thiet bi:";
    cout << setw(30) << right << tongSoLuongThietBi << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Giam hieu";
    cout << setw(20) << "Khoa CNTT";
    cout << setw(20) << "Nguoi Lap" << endl;
}

int main()
{
    PhieuThongKeThietBi phieuThongKeThietBi;
    phieuThongKeThietBi.Nhap();
    phieuThongKeThietBi.Xuat();
    return 0;
}
