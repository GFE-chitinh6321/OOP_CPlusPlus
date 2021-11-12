#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class HanhKhach {
  private:
    char tenChuyen[30];
    char ngayBay[15];
    double giaVe;
    int soLuong;
  public:
    HanhKhach() {
      strcpy(this->tenChuyen, "");
      strcpy(this->ngayBay, "");
      giaVe = 0.0;
      soLuong = 0;
    }

    HanhKhach(char tenChuyen[], char ngayBay[], double giaVe, int soLuong) {
      strcpy(this->tenChuyen, tenChuyen);
      strcpy(this->ngayBay, ngayBay);
      this->giaVe = giaVe;
      this->soLuong = soLuong;
    }

    ~HanhKhach() {
      strcpy(this->tenChuyen, "");
      strcpy(this->ngayBay, "");
      giaVe = 0.0;
      soLuong = 0;
    }

    double getGiaVe() {
      return this->giaVe;
    }

    double tongTien() {
      return this->giaVe * this->soLuong;
    }
    void nhap();
    void xuat();
};

void HanhKhach::nhap() {
  cout << "\tTen chuyen: ";       fflush(stdin);    gets(tenChuyen);
  cout << "\tNgay bay: ";         fflush(stdin);    gets(ngayBay);
  cout << "\tGia ve: ";           cin >> giaVe;
  cout << "\tSo luong: ";         cin >> soLuong;
}

void HanhKhach::xuat() {
  cout << "\tTen chuyen: " << tenChuyen << endl;
  cout << "\tNgay bay: " << ngayBay << endl;
  cout << "\tGia ve: " << giaVe << endl;
  cout << "\tSo luong: " << soLuong << endl;
  cout << "\tSo tien phai tra: " << tongTien() << " VND" << endl;
  cout << "---------" << endl;
}

void sapXepGiamDanTongTien(HanhKhach hanhKhach[], int soLuongHanhKhach) {
  for (int i = 0; i < soLuongHanhKhach; i++) {
    for (int j = i + 1; j <= soLuongHanhKhach; j++) {
      if (hanhKhach[i].tongTien() < hanhKhach[j].tongTien()) {
        HanhKhach temp = hanhKhach[i];
        hanhKhach[i] = hanhKhach[j];
        hanhKhach[j] = temp;
      }
    }
  }
}

main() {
  HanhKhach *hanhKhach;
  int soLuongHanhKhach;
  cout << "Nhap so luong hanh khach: ";   cin >> soLuongHanhKhach;
  hanhKhach = new HanhKhach[soLuongHanhKhach];
  for(int i = 0; i < soLuongHanhKhach; i++) {
    cout << "Nhap thong tin hanh khach " << i + 1 << ": " << endl;
    hanhKhach[i].nhap();
  }
  cout << "--------------------------------------------------" << endl;
  cout << "DANH SACH HANH KHACH" << endl;
  for(int i = 0; i < soLuongHanhKhach; i++) {
    cout << "Hanh khach " << i + 1 << ": " << endl;
    hanhKhach[i].xuat();
  }
  sapXepGiamDanTongTien(hanhKhach, soLuongHanhKhach);
  cout << "--------------------------------------------------" << endl;
  cout << "DANH SACH HANH KHACH SAU KHI SAP XEP" << endl;
  for(int i = 0; i < soLuongHanhKhach; i++) {
    hanhKhach[i].xuat();
  }
}