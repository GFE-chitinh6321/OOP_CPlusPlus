#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class LopHoc;

class Nguoi {
protected:
    char hoTen[30];
    char ngaySinh[30];
    char queQuan[30];
public:
    void nhap();
    void xuat();
};

class SinhVien : public Nguoi {
private:
    char maSinhVien[30];
    char nganh[30];
    int khoaHoc;
public:
    void nhap();
    void xuat();
    friend int sinhVienKhoa11(LopHoc lopHoc);
    friend void sapXepDanhSachSinhVien(LopHoc lopHoc);
};

class LopHoc {
private:
    char maLop[30];
    char tenLop[30];
    char ngayMo[30];
    SinhVien *sinhVien;
    int n;
    char giaoVien[30];
public:
    void nhap();
    void xuat();
    friend int sinhVienKhoa11(LopHoc lopHoc);
    friend void sapXepDanhSachSinhVien(LopHoc lopHoc);

};

void Nguoi::nhap(){
    cout << "\tHo ten: ";           fflush(stdin);      gets(hoTen);
    cout << "\tNgay sinh: ";        fflush(stdin);      gets(ngaySinh);
    cout << "\tQue quan: ";         fflush(stdin);      gets(queQuan);
}

void Nguoi::xuat() {
    cout << setw(20) << hoTen;
    cout << setw(20) << ngaySinh;
    cout << setw(20) << queQuan << endl;
}

void SinhVien::nhap() {
    cout << "\tMa sinh vien: ";     fflush(stdin);      gets(maSinhVien);
    cout << "\tNganh: ";            fflush(stdin);      gets(nganh);
    cout << "\tKhoa hoc: ";         cin >> khoaHoc;
    Nguoi::nhap();
}

void SinhVien::xuat(){
    cout << setw(20) << maSinhVien;
    cout << setw(20) << nganh;
    cout << setw(20) << khoaHoc;
    Nguoi::xuat();
}

void tieuDeBangSinhVien(){
    cout << setw(20) << "Ma sinh vien";
    cout << setw(20) << "Nganh";
    cout << setw(20) << "Khoa hoc";
    cout << setw(20) << "Ho ten";
    cout << setw(20) << "Ngay sinh";
    cout << setw(20) << "Que quan" << endl;

}

void LopHoc::nhap(){
    cout << "Nhap thong tin cua lop: " << endl;
    cout << "\tMa lop: ";           fflush(stdin);      gets(maLop);
    cout << "\tTen lop: ";          fflush(stdin);      gets(tenLop);
    cout << "\tNgay mo: ";          fflush(stdin);      gets(ngayMo);
    cout << "Nhap so luong sinh vien: ";                cin >> n;
    sinhVien = new SinhVien[n];
    for (int i=0; i<n; i++){
        cout << "Nhap thong tin sinh vien " << i+1 << ": " << endl;
        sinhVien[i].nhap();
    }
}

void LopHoc::xuat(){
    cout << "Ma lop: " << maLop << endl;
    cout << "Ten lop: " << tenLop << endl;
    cout << "Ngay mo: " << ngayMo << endl;
    cout << "DANH SACH SINH VIEN" << endl;
    cout << "--------------------------------" << endl;
    tieuDeBangSinhVien();
    for (int i=0; i<n; i++){
        sinhVien[i].xuat();
    }
     cout << "-----------------------------------------------------------------------------------------" << endl;
}

int sinhVienKhoa11(LopHoc lopHoc) {
    int countStudent = 0;
    for (int i=0; i<lopHoc.n; i++){
        if (lopHoc.sinhVien[i].khoaHoc == 11) {
            countStudent++;
        }
    }
    return countStudent;
}

void sapXepDanhSachSinhVien(LopHoc lopHoc) {
    for(int i=0; i<lopHoc.n; i++)
    for(int j=i+1; j<lopHoc.n; j++){
        if(lopHoc.sinhVien[i].khoaHoc > lopHoc.sinhVien[j].khoaHoc){
            SinhVien sinhVien;
            sinhVien = lopHoc.sinhVien[i];
            lopHoc.sinhVien[i] = lopHoc.sinhVien[j];
            lopHoc.sinhVien[j] = sinhVien;
        }
    }
}

int main()
{
    LopHoc lopHoc;
    lopHoc.nhap();
    lopHoc.xuat();
    cout << "So luong sinh vien khoa 11: " << sinhVienKhoa11(lopHoc) << endl;
    sapXepDanhSachSinhVien(lopHoc);
    cout << "Danh sach sinh vien sau khi sap xep: " << endl;
    lopHoc.xuat();


}
