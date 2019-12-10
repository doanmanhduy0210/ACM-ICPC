#include <bits/stdc++.h>
using namespace std;
class thuoc;
class benhnhan
{
    char hoten[30];
    char gioitinh[10];
    int thoigiandieutri;
    char mottabenh[30];
public:
    friend istream& operator>>(istream& in, benhnhan &p);
    friend ostream& operator<<(ostream& out, const benhnhan &p);
    friend void lieuluong(thuoc x, benhnhan y);
};


istream& operator>>(istream& in, benhnhan &p)
{
    cout<<"nhap ho ten benh nhan: ";                    fflush(stdin);      gets(p.hoten);
    cout<<"nhap thoi gian dieu tri cho benh nhanh : ";  fflush(stdin);      in>>p.thoigiandieutri;
    cout<<"nhap gioi tinh benh nhan: ";                 fflush(stdin);      in>>p.gioitinh;
    cout<<"nhap mo ta benh: ";                          fflush(stdin);      gets(p.mottabenh);
    return in;
}
ostream& operator<<(ostream& out, const benhnhan &p)
{

    out<<"Ho va ten benh nhan:  "<<p.hoten<<setw(30) <<"Thoi gian dieu tri: "<<p.thoigiandieutri  <<endl;
    out<<"Gioi tinh: "<<p.gioitinh<<endl;
    out<<"Mo ta: "<<p.mottabenh<<endl;
    return out;
}

class thuoc
{
    char tenthuoc[20];
    char donvi[20];
    int soluong;
public:
    friend void lieuluong(thuoc x, benhnhan y);
    friend istream& operator>>(istream& in, thuoc &h);
    friend ostream& operator<<(ostream& out, const thuoc &h);

};

istream& operator>>(istream& in, thuoc &h)
{
    cout<<"nhap ten thuoc : ";          fflush(stdin);          gets(h.tenthuoc);
    cout<<"nhap don vi tinh : ";        fflush(stdin);          in>>h.donvi;
    cout<<"nhap so luong: ";                                    in>>h.soluong;
    return in;
}

ostream& operator<<(ostream& out, const thuoc &h)
{
    out<<"\t"<<h.tenthuoc<<"\t\t"<<h.donvi<<"\t\t"<<h.soluong;
    return out;
}


class Donthuoc:public benhnhan , thuoc
{
    char ngaynhap[20];
    char tenbs[20];
    benhnhan x;
    thuoc *a;
    int n;
public:
    friend void lieuluong(thuoc x, benhnhan y);
    friend istream& operator>>(istream& in, Donthuoc &d);
    friend ostream& operator<<(ostream& out, const Donthuoc &d);

};
void lieuluong(thuoc x, benhnhan y)
{
    cout <<"\t\t "<< x.soluong/y.thoigiandieutri<<"("<<x.donvi<<")";
}

istream& operator>>(istream& in, Donthuoc &d)
{
    cout<<"Ngay nhap vien  : ";         fflush(stdin);          in>>d.ngaynhap;
    cout<<"nhap Ten bac si : ";         fflush(stdin);          gets(d.tenbs);
    in>>d.x;
    cout << endl;
    cout << " nhap so luong thuoc: ";                           in>>d.n;
    d.a = new thuoc[d.n];
    for(int i=0; i<d.n; i++)
    {
        cout << " nhap thuoc thu: "<< i+1 << endl;
        in>>d.a[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Donthuoc &d)
{
    cout<<setw(40) <<" DON THUOC " <<endl;
    out<<"Ngay nhap vien: "<<d.ngaynhap<<setw(30)<<"Bac sy dieu tri: " <<d.tenbs<<endl;
    out<<d.x << endl;
    out<<"\t "<<"Ten thuoc "<<"\t"<<"Don vi tinh "<<"\t"<<"So luong"<<"\t"<<"Lieu luong/1ngay "<<endl;
    for(int i=0; i<d.n; i++)
    {
        out<< d.a[i];
        lieuluong(d.a[i],d.x);
        out << "\n";
    }
    return out;
}



int main()
{
    Donthuoc a;
    cin>>a;
    cout<<"\n\n"<<a;

    return 0;
}
