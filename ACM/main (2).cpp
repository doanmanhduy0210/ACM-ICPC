#include <iostream>
#include<bits/stdc++.h>

using namespace std;
void NHAP(double *&a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
}
void XUAT(double *a, int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
void SAP(double *a, int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;i++)
        if(a[i]>a[j])
        {
            int tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }
    a=(double*) realloc(a, n*sizeof(float));
}
float TINH(double *a, int n)
{
    double t=0;
    for(int i=0;i<n;i++)
        if(i%2==0)
        t=t+a[i];
    return t;
}

float MAX(double *a,int n)
{   float M=a[0];
    for(int i=1;i<n;i++)
    if(a[i]>M)
        M=a[i];
    return M;
}
float MAX2(double *a, int n)
{
    float M=a[0];
    for(int i=1;i<n;i++)
    if(a[i]>M)
        M=a[i];
    float max2=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max2 && a[i]<M)
            max2=a[i];
    return max2;
}
float KT(double *a, int n)
{
    for(int i=0;i<n-2;i++)
        if(a[0]>0 && a[i+1]>0 && a[i+2]) return 1;
        else return 2;
}
void XOA(double *a, int n)
{
    for(int i=0;i<n;i++)
        if(a[i]>5)
    {
        for(int j=i;j<n;j++)
            a[j]=a[j+1];
        n--;
    }
    a=(double*) realloc(a, n*sizeof(float));
}
int main()
{
    int n;
    double *a;
    cout<<"n= ";cin>>n;
    a=new double[n];
    NHAP(a,n);
    cout<<"sap tang dan la ";
    SAP(a,n);
    XUAT(a,n);
    cout<<"tong chi so chia het cho 2 la "<<TINH(a,n)<<endl;
    ofstream f("D: /text.txt", ios::out);
    {
    for(int i=0;i<n;i++)
        {
            f<<n<<endl;
            f<<a[i]<<" "<<endl;
            f<<" end ";
        }
    }
    cout<<"phan tu lon nhat trong mang la "<<MAX(a,n)<<endl;
    cout<<"phan tu lon thu 2 trong mang la "<<MAX2(a,n)<<endl;
    float T=KT(a,n);
    if(T==1) cout<<"co chua 3 so duong lien tiep "<<endl;
    if(T==2) cout<<"khong chua 3 so duong lien tiep "<<endl;
    cout<<"mang sau khi xoa la ";
    XOA(a,n);
    XUAT(a,n);
}
