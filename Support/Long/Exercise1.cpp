#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class NhanVien;

class Date {
  private:
    int ngay;
    int thang;
    int nam;
  public:
    friend class NhanVien;
};

class PhongBan {
  private:
    char tenPhong[30];
    char maPhong[10];
    char truongPhong[30];
  public:
    friend class NhanVien;
    friend void hienThiNhanVienPhongTaiChinh(NhanVien nhanVien[], int soLuongNhanVien);
};

class NhanVien {
  private:
    char maNhanVien[10];
    char tenNhanVien[30];
    PhongBan phongBan;
    Date date;
  public:
    void nhap();
    void xuat();
    friend void hienThiNhanVienPhongTaiChinh(NhanVien nhanVien[], int soLuongNhanVien);
};

void NhanVien::nhap() {
  cout << "\tMa nhan vien: ";     fflush(stdin);      gets(maNhanVien);
  cout << "\tTen nhan vien: ";    fflush(stdin);      gets(tenNhanVien);
  cout << "\tTen phong: ";        fflush(stdin);      gets(phongBan.tenPhong);
  cout << "\tMa phong: ";         fflush(stdin);      gets(phongBan.maPhong);
  cout << "\tTruong phong: ";     fflush(stdin);      gets(phongBan.truongPhong);
  cout << "\tNgay: (dd/mm/yyyy) ";                    cin >> date.ngay >> date.thang >> date.nam;       
}

void NhanVien::xuat() {
  cout << "\tMa nhan vien: " << maNhanVien << endl;
  cout << "\tTen nhan vien: " << tenNhanVien << endl;
  cout << "\tTen phong: " << phongBan.tenPhong << endl;
  cout << "\tMa phong: " << phongBan.maPhong << endl;
  cout << "\tTruong phong: " << phongBan.truongPhong << endl;
  cout << "\tNgay: " << date.ngay << "/" << date.thang << "/" << date.nam << endl;
  cout << "-------------" << endl;
}

void hienThiNhanVienPhongTaiChinh(NhanVien nhanVien[], int soLuongNhanVien) {
  int demNhanVien = 0;
  for (int i = 0; i < soLuongNhanVien; i++) {
    if (strcmp(nhanVien[i].phongBan.tenPhong, "tai chinh") == 0) 
      demNhanVien++;
  }

  if (demNhanVien == 0) {
    cout << "Khong co nhan vien nao thuoc phong tai chinh." << endl;
  } else {
    cout << "Co " << demNhanVien << " thuoc phong tai chinh." << endl;
  }

  for (int i = 0; i < soLuongNhanVien; i++) {
    if (strcmp(nhanVien[i].phongBan.tenPhong, "tai chinh") == 0) 
      nhanVien[i].xuat();
  }
}

main() {
  NhanVien *nhanVien;
  int soLuongNhanVien;
  cout << "Nhap so luong nhan vien: ";   cin >> soLuongNhanVien;
  nhanVien = new NhanVien[soLuongNhanVien];
  for(int i = 0; i < soLuongNhanVien; i++) {
    cout << "Nhap thong tin nhan vien " << i + 1 << ": " << endl;
    nhanVien[i].nhap();
  }
  cout << "--------------------------------------------------" << endl;
  cout << "DANH SACH NHAN VIEN" << endl;
  for(int i = 0; i < soLuongNhanVien; i++) {
    nhanVien[i].xuat();
  }
  hienThiNhanVienPhongTaiChinh(nhanVien, soLuongNhanVien);
}
