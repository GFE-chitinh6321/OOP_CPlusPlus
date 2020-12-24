#include <iostream>

using namespace std;
class Thetich{
private:
      int a,b,c;
public:
      Thetich(){
            a=b=c=1;
      }
      Thetich(int x=0,int y=0,int z=0)
      {
            a=x;
            b=y;
            c=z;
      }
      //friend istream&operator>>(istream &is,Thetich &ob);
      friend ostream&operator<<(ostream &os,Thetich ob);

      friend int Tinh(Thetich v){
            return v.a*v.b*v.c;
      }
      friend int operator +(Thetich v,Thetich m);
      friend int operator -(Thetich v,Thetich m);
};
 int operator +(Thetich v,Thetich m){
      return v.a*v.b*v.c+m.a*m.b*m.c;
}
 int operator -(Thetich v,Thetich m){
      return v.a*v.b*v.c-m.a*m.b*m.c;
}
ostream &operator<<(ostream &os,Thetich ob){
      int v=0;
      os<<ob.a*ob.b*ob.c;
      return os;
}

int main()
{
      Thetich x(3,2,1);
      Thetich y(6,5,4);
      Tinh(x);
      cout<<"the tich hinh hop x: "<<x<<endl;
      Tinh(y);
      cout<<"the tich hinh hop y: "<<y<<endl;
      cout<<"the tich cua hinh y la: "<<y<<endl;
      cout<<"tong the tich cua x+y: "<<x+y<<endl;
      cout<<"hieu the tich cua x-y: "<<x-y<<endl;
    return 0;
}
/*
class Tamthuc
{
private:
      int a,b,c;
public:
      Tamthuc(int x=0,int y=0,int z=0)
      {
            a=x;
            b=y;
            c=z;
      }
      // friend istream& operator>>(istream& s,Tamthuc& d);
      friend ostream&operator<<(ostream&os,const Tamthuc &v);
      Tamthuc operator+(Tamthuc&v);
      Tamthuc operator-(Tamthuc&v);
      Tamthuc operator-();
};
/*istream& operator>>(istream& s,Tamthuc& d)
{
      cout<<"nhap so 1";           s>>d.a;
      cout<<"nhap so 2";          s>>d.b;
      cout<<"nhap so 3";          s>>d.c;
      return s;
}
ostream&operator<<(ostream&os,const Tamthuc&v)
{
      os<<v.a<<"x2+ "<<v.b<<" x +"<<v.c;
      return os;
}
Tamthuc Tamthuc::operator+(Tamthuc &v)
{
      Tamthuc obj;
      obj.a=a+v.a;
      obj.b=b+v.b;
      obj.c=c+v.c;
      return obj;
}
Tamthuc Tamthuc::operator-(Tamthuc &v)
{
      Tamthuc obj;
      obj.a=a-v.a;
      obj.b=b-v.b;
      obj.c=c-v.c;
      return obj;
}
Tamthuc Tamthuc::operator-()
{
      a=-a;
      b=-b;
      c=-c;
      return *this;
}
int main(){
      Tamthuc a(2,4,-5),b(3,3,-6),m;
      cout<<a;
      cout<<endl;
      cout<<b;
      cout<<endl;
      m=a+b;
      cout<<m;
      a=-a;
      cout<<a;
}
*/
