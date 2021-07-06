#include <bits/stdc++.h>

using namespace std;

class PHIEU;
class NHACUNGCAP
{
    char mancc[20];
    char tenncc[40];
    char diachi[30];
    char sdt[12];
public:
    void nhap();
    void xuat();
};

void NHACUNGCAP::nhap()
{
    cout<<"MA NCC: ";   fflush(stdin); gets(mancc);
    cout<< "TEN NCC: "; fflush(stdin); gets(tenncc);
    cout<<"DIA CHI: ";  fflush(stdin); gets(diachi);
    cout<< "SDT: ";     fflush(stdin); gets(sdt);
}
void NHACUNGCAP::xuat()
{
    cout<<setw(20)<<"Ma nha cung cap: "<<setw(10)<<mancc
        <<setw(20)<<"Ten nha cung cap: "<<setw(15)<<tenncc<<endl;
    cout<<setw(10)<<"Dia chi: "<<setw(20)<<diachi<<setw(10)
        <<"SDT: "<<setw(12)<<sdt<<endl;
}

class SANPHAM
{
    char masp[20];
    char tensp[30];
    int soluong;
    float dongia;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend int demSanPham(PHIEU ph);
    friend void sapXep(PHIEU ph);
};
void SANPHAM::nhap()
{
    cout<<"MA SP: ";    fflush(stdin); gets(masp);
    cout<<"TEN SP: ";   fflush(stdin); gets(tensp);
    cout<<"SO LUONG: "; cin>>soluong;
    cout<<"DON GIA: ";  cin>>dongia;
}

void SANPHAM::xuat()
{
    cout<<setw(10)<<masp<<setw(15)<<tensp<<setw(10)<<soluong
        <<setw(10)<<dongia<<setw(15)<<soluong*dongia<<endl;
}

class PHIEU
{
    char maphieu[20];
    char ngaylap[12];
    NHACUNGCAP x;
    SANPHAM *y;
    int n;
public:
    void nhap();
    void xuat();
    friend int demSanPham(PHIEU ph);
    friend void sapXep(PHIEU ph);
};

void PHIEU::nhap()
{
    cout<< "MA PHIEU: "; fflush(stdin); gets(maphieu);
    cout<< "NGAY LAP: "; fflush(stdin); gets(ngaylap);
    x.nhap();
    cout<<"NHAP SO LUONG HANG: "; cin>>n;
    y = new SANPHAM[n];
    for(int i=0; i<n; i++)
        y[i].nhap();
}

void PHIEU::xuat()
{
    cout<<"Dai hoc Victory"<<endl;
    cout<<"\t\tPHIEU NHAP VAN PHONG PHAM"<<endl;
    cout<<setw(20)<<"Ma phieu: "<<setw(10)<<maphieu
        <<setw(20)<<"Ngay lap: "<<setw(12)<<ngaylap<<endl;
    x.xuat();

    cout<<setw(10)<<"Ma SP"<<setw(15)<<"Ten san pham"<<setw(10)<<"So luong"
        <<setw(10)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
    for(int i=0; i<n; i++)
        y[i].xuat();

    float tong =0;
    for(int i=0; i<n; i++)
        tong+=(y[i].soluong * y[i].dongia);
    cout <<setw(45)<< "Tong: " <<setw(15)<<tong<<endl;

    cout<<setw(20)<<"Hieu truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
}

int demSanPham(PHIEU ph)
{
    int dem=0;
    for(int i=0; i<ph.n; i++)
        if(ph.y[i].soluong<80)
            dem++;
    return dem;
}

void sapXep(PHIEU ph)
{
    for(int i=0; i<ph.n; i++)
    for(int j=i+1; j<ph.n; j++)
        if(ph.y[i].dongia>ph.y[j].dongia)
        {
            SANPHAM s;
            s = ph.y[i];
            ph.y[i]=ph.y[j];
            ph.y[j]=s;
        }
            //swap(ph.y[i], ph.y[j]);
}


int main()
{
    PHIEU ph;
    ph.nhap();
    ph.xuat();
    cout<<"So san pham co so luong nhap nho hon 80: "<<demSanPham(ph)<<" san pham."<<endl;
    sapXep(ph);
    cout<<"\n\n******************PHIEU SAU KHI DA SAP XEP******************"<<endl;
    ph.xuat();
    return 0;
}
