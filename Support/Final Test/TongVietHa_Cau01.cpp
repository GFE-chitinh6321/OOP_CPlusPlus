#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Hang {
protected:
    char maHang[30];
    char tenHang[30];
    float gia;
public:
    void Nhap();
    void Xuat();
};

class HangMayMac : public Hang {
private:
    char chatLieu[30];
    char kieuDang[30];
    int soLuong;
public:
    void Nhap();
    void Xuat();
};

class CuaHang {
private:
    char maCuaHang[30];
    char tenCuaHang[30];
    HangMayMac *hangMayMac;
    int n;
public:
    void Nhap();
    void Xuat();
};

void Hang :: Nhap(){
    cout << "\t Ma hang: ";                 fflush(stdin);      gets(maHang);
    cout << "\t Ten hang: ";                fflush(stdin);      gets(tenHang);
    cout << "\t Gia: ";                     cin >> gia;
}

void Hang::Xuat() {
    cout << setw(20) << maHang;
    cout << setw(20) << tenHang;
    cout << setw(20) << gia;
}

void HangMayMac::Nhap(){
    Hang::Nhap();
    cout << "\t Chat lieu: ";               fflush(stdin);      gets(chatLieu);
    cout << "\t Kieu dang: ";               fflush(stdin);      gets(kieuDang);
    cout << "\t So luong: ";                cin >> soLuong;
}

void HangMayMac::Xuat() {
    Hang::Xuat();
    cout << setw(20) << chatLieu;
    cout << setw(20) << kieuDang;
    cout << setw(20) << soLuong << endl;
}

void CuaHang::Nhap(){
    cout << "Nhap thong tin cua hang:" << endl;
    cout << "\t MA CUA HANG: ";             fflush(stdin);      gets(maCuaHang);
    cout << "\t TEN CUA HANG: ";            fflush(stdin);      gets(tenCuaHang);
    cout << "Nhap so luong hang may mac: "; cin >> n;
    hangMayMac = new HangMayMac[n];
    for (int i=0; i<n; i++){
        cout << "Nhap thong tin cho mat hang " << i+1 << ":" << endl;
        hangMayMac[i].Nhap();
    }
}

void tieuDeHangHoa() {
    cout << setw(20) << "Ma hang";
    cout << setw(20) << "Ten hang";
    cout << setw(20) << "Gia";
    cout << setw(20) << "Chat lieu";
    cout << setw(20) << "Kieu dang";
    cout << setw(20) << "So luong" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
}

void CuaHang::Xuat() {
    cout << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Thong tin cua hang: " << endl;
    cout << "Ma cua hang: " << maCuaHang << endl;
    cout << "Ten cua hang: " << tenCuaHang << endl;
    cout << "Thong tin hang may mac: " << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    tieuDeHangHoa();
    for(int i=0; i<n; i++){
        hangMayMac[i].Xuat();
    }
}


int main()
{
    CuaHang cuaHang;
    cuaHang.Nhap();
    cuaHang.Xuat();
    return 0;
}
