#include <bits/stdc++.h>

using namespace std;
class LOPHOC;

class NGUOI
{
protected:
    char hoten[30];
    char ngaysinh[12];
    char quequan[30];
public:
    void nhap();
    void xuat();
};

void NGUOI::nhap()
{
    cout<<"Ho ten: ";       fflush(stdin);      gets(hoten);
    cout<<"Ngay sinh: ";    fflush(stdin);      gets(ngaysinh);
    cout<<"Que quan: ";     fflush(stdin);      gets(quequan);
}

void NGUOI::xuat()
{
    cout<<setw(15)<<hoten<<setw(12)<<ngaysinh<<setw(15)<<quequan<<endl;
}


class SINHVIEN : public NGUOI
{
    char masvien[20];
    char nganh[30];
    int khoahoc;
public:
    void nhap();
    void xuat();
    friend void svkhoa11(LOPHOC k);
    friend void sapxep(LOPHOC k);
};

void SINHVIEN::nhap()
{
    cout<<"Ma sinh vien: ";     fflush(stdin);     gets(masvien);
    cout<<"Nganh: ";            fflush(stdin);     gets(nganh);
    cout<<"Khoa hoc: ";         cin>>khoahoc;
    NGUOI::nhap();
}

void SINHVIEN::xuat()
{
    cout<<setw(10)<<masvien<<setw(15)<<nganh<<setw(15)<<khoahoc;
    NGUOI::xuat();
}

class LOPHOC
{
    char malop[20];
    char tenlop[30];
    char ngaymo[12];
    SINHVIEN *x;
    int n;
    char giaovien[30];
public:
    void nhap();
    void xuat();
    friend void svkhoa11(LOPHOC k);
    friend void sapxep(LOPHOC k);
};

void LOPHOC::nhap()
{
    cout<<"Ma Lop: "; fflush(stdin); gets(malop);
    cout<< "Ten lop: "; fflush(stdin); gets(tenlop);
    cout<< "Ngay mo: "; fflush(stdin); gets(ngaymo);
    cout<< "Giao vien: "; fflush(stdin); gets(giaovien);

    cout<<"So sinh vien: ";
    cin>>n;
    x = new SINHVIEN[n];
    for(int i=0; i<n; i++)
        x[i].nhap();

}

void LOPHOC::xuat()
{
    cout<<"Ma Lop: "<<malop<<endl;
    cout<< "Ten lop: "<<tenlop<<endl;
    cout<< "Ngay mo: "<<ngaymo<<endl;
    cout<< "Giao vien: "<<giaovien<<endl;

    cout<<setw(10)<<"MA SV"<<setw(15)<<"NGANH"<<setw(15)<<"KHOA HOC";
    cout<<setw(15)<<"HO TEN"<<setw(12)<<"NGAY SINH"<<setw(15)<<"QUEN QUAN"<<endl;
    for(int i=0; i<n; i++)
        x[i].xuat();
}

void svkhoa11(LOPHOC k)
{
    int dem=0;
    for(int i=0; i<k.n; i++)
        if(k.x[i].khoahoc==11)
            dem++;
    cout<<endl<<"So sinh vien khoa 11: "<<dem<<endl;
}
void sapxep(LOPHOC k)
{
    for(int i=0; i<k.n; i++)
    for(int j=i+1; j<k.n; j++)
        if(k.x[i].khoahoc>k.x[j].khoahoc){
            SINHVIEN s;
            s = k.x[i];
            k.x[i]=k.x[j];
            k.x[j]= s;
        }

}
int main()
{
    LOPHOC khmt1;
    khmt1.nhap();
    khmt1.xuat();
    svkhoa11(khmt1);
    cout<<"-----------------Sinh vien sau khi duoc sap xep---------------"<<endl;
    sapxep(khmt1);
    khmt1.xuat();

    return 0;
}
