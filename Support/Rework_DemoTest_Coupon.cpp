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
    char maPhongMay[30];
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
    int n;
public:
    void Nhap();
    void Xuat();
};

void PhieuThongKeThietBi::Nhap() {
    cout << "Nhap thong tin phieu: " << endl;
    cout << "\t Ngay lap: ";                        fflush(stdin);      gets(phieu.ngayLap);
    cout << "\t Nguoi lap: ";                       fflush(stdin);      gets(phieu.nguoiLap);
    cout << "\t Ma phong may: ";                    fflush(stdin);      gets(phieu.maPhongMay);
    cout << "\t Ten phong: ";                       fflush(stdin);      gets(phieu.tenPhong);
    cout << "\t Ten nguoi quan ly: ";               fflush(stdin);      gets(phieu.tenNguoiQuanLy);
    cout << "Nhap so luong thiet bi: ";             cin >> n;
    thietBi = new ThietBi[n];
    for (int i=0; i<n; i++){
        cout << "Nhap thong tin thiet bi " << i+1 << ":" << endl;
        cout << "\t Ma thiet bi: ";                 fflush(stdin);      gets(thietBi[i].maThietBi);
        cout << "\t Ten thiet bi: ";                fflush(stdin);      gets(thietBi[i].tenThietBi);
        cout << "\t Tinh trang: ";                  fflush(stdin);      gets(thietBi[i].tinhTrang);
        cout << "\t So luong: ";                    cin >> thietBi[i].soLuong;
    }
}

void tieuDeBangThietBi() {
    cout << setw(20) << "Ma thiet bi";
    cout << setw(20) << "Ten thiet bi";
    cout << setw(20) << "Tinh trang";
    cout << setw(20) << "So luong" << endl;
}

void PhieuThongKeThietBi::Xuat() {
    cout << "TRUONG DHCNHN" << endl;
    cout << setw(50) << "BANG THONG KE THIET BI" << endl;
    cout << setw(20) << left << "Ngay lap: ";
    cout << setw(20) << phieu.ngayLap;
    cout << setw(20) << "Nguoi lap: ";
    cout << setw(20) << phieu.nguoiLap << endl;
    cout << setw(20) << left << "Ma phong may: ";
    cout << setw(20) << phieu.maPhongMay;
    cout << setw(20) << "Ten phong: ";
    cout << setw(20) << phieu.tenPhong << endl;
    cout << setw(20) << left << "Ten nguoi quan ly: ";
    cout << setw(20) << phieu.tenNguoiQuanLy << endl;
    cout << "Chi tiet:" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    tieuDeBangThietBi();
    cout << "----------------------------------------------------------------------------" << endl;
    int tongSoLuongThietBi = 0;
    for(int i=0; i<n; i++){
        cout << setw(20) << thietBi[i].maThietBi;
        cout << setw(20) << thietBi[i].tenThietBi;
        cout << setw(20) << thietBi[i].tinhTrang;
        cout << setw(20) << thietBi[i].soLuong << endl;
        tongSoLuongThietBi += thietBi[i].soLuong;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << setw(30) << "Tong so luong thiet bi: ";
    cout << setw(30) << right << tongSoLuongThietBi << endl << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Giam hieu";
    cout << setw(20) << "Khoa CNTT";
    cout << setw(20) << "Nguoi lap" << endl;
}

int main()
{
    PhieuThongKeThietBi phieuThongkeThietBi;
    phieuThongkeThietBi.Nhap();
    phieuThongkeThietBi.Xuat();
    return 0;


}
