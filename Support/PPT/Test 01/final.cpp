#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class BangLuong;

class ThongTinBang {
private:
    char ngayLap[30];
    char nguoiLap[30];
    char maDonVi[30];
    char tenDonVi[30];
public:
    friend class BangLuong;
};

class NhanSu {
private:
    char maNhanSu[30];
    char tenNhanSu[30];
    float heSoLuong;
    float luong;
public:
    friend class BangLuong;
    friend void sapXepDanhSachNhanSu(BangLuong bangLuong);
    friend void suaThongTinNhanSu(BangLuong bangLuong);
};


class BangLuong {
private:
    ThongTinBang thongTinBang;
    NhanSu *nhanSu;
    int n;
public:
    void nhap();
    void xuat();
    friend void sapXepDanhSachNhanSu(BangLuong bangLuong);
    friend void suaThongTinNhanSu(BangLuong bangLuong);
};

void BangLuong ::nhap(){
    cout << "Nhap thong tin bang luong: " << endl;
    cout << "\tNgay lap: ";         fflush(stdin);      gets(thongTinBang.ngayLap);
    cout << "\tNguoi lap: ";        fflush(stdin);      gets(thongTinBang.nguoiLap);
    cout << "\tMa don vi: ";        fflush(stdin);      gets(thongTinBang.maDonVi);
    cout << "\tTen don vi: ";       fflush(stdin);      gets(thongTinBang.tenDonVi);
    cout << "Nhap so luong nhan su: ";                  cin >> n;
    nhanSu = new NhanSu[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin nhan su " << i+1 << ": " << endl;
        cout << "\tMa nhan su: ";   fflush(stdin);      gets(nhanSu[i].maNhanSu);
        cout << "\tTen nhan su: ";  fflush(stdin);      gets(nhanSu[i].tenNhanSu);
        cout << "\tHe so luong: ";  cin >> nhanSu[i].heSoLuong;
        cout << "\tLuong: ";        cin >> nhanSu[i].luong;
    }
}

void tieuDeBangNhanSu() {
    cout << setw(20) << "Ma nhan su";
    cout << setw(20) << "Ten nhan su";
    cout << setw(20) << "He so luong";
    cout << setw(20) << "Luong" << endl;
}

void BangLuong::xuat(){
    cout << "---------------------------------------------------------------" << endl;
    cout << "TRUONG DHCNHN" << endl;
    cout << setw(50) << "BANG LUONG THANG 6/2017" << endl;
    cout << setw(20) << left << "Ngay lap: ";
    cout << setw(20) << thongTinBang.ngayLap;
    cout << setw(20) << "Nguoi lap: ";
    cout << setw(20) << thongTinBang.nguoiLap << endl;
    cout << setw(20) << left << "Ma don vi: ";
    cout << setw(20) << thongTinBang.maDonVi;
    cout << setw(20) << "Ten don vi: ";
    cout << setw(20) << thongTinBang.tenDonVi << endl;
    cout << "---------------------------------" << endl;
    tieuDeBangNhanSu();
    float tongLuong = 0;
    for(int i=0; i<n; i++){
        cout << setw(20) << nhanSu[i].maNhanSu;
        cout << setw(20) << nhanSu[i].tenNhanSu;
        cout << setw(20) << nhanSu[i].heSoLuong;
        cout << setw(20) << nhanSu[i].luong << endl;
        tongLuong += nhanSu[i].luong;
    }
    cout << setw(60) << left << "Tong cong: ";
    cout << setw(20) << tongLuong << endl;
    cout << "---------------------------------------------------------------" << endl;

}

void sapXepDanhSachNhanSu(BangLuong bangLuong) {
    for (int i=0; i<bangLuong.n; i++)
    for(int j=i+1; j<bangLuong.n; j++){
        if(bangLuong.nhanSu[i].heSoLuong < bangLuong.nhanSu[j].heSoLuong){
            NhanSu nhanSu;
            nhanSu = bangLuong.nhanSu[i];
            bangLuong.nhanSu[i] = bangLuong.nhanSu[j];
            bangLuong.nhanSu[j] = nhanSu;
        }
    }
}

void suaThongTinNhanSu(BangLuong bangLuong) {
    for(int i=0; i<bangLuong.n; i++){
        if(strcmp(bangLuong.nhanSu[i].maNhanSu, "NS001")){
             strcpy(bangLuong.nhanSu[i].tenNhanSu, "Vu Viet Thang");
        }
    }
}

int main()
{
    BangLuong bangLuong;
    bangLuong.nhap();
    bangLuong.xuat();
    sapXepDanhSachNhanSu(bangLuong);
    cout << "BANG LUONG SAU KHI SAP XEP" << endl;
    bangLuong.xuat();
    suaThongTinNhanSu(bangLuong);
    cout << "BANG LUONG SAU KHI SUA THONG TIN" << endl;
    bangLuong.xuat();

}
