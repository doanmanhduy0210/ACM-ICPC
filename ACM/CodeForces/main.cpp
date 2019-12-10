#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main()
{
    int n;
    cin >> n;
    long long temp2=0;
    a[0]=0;
    for(int i=1; i<5000; i++)
    {
        if(i%2!=0&&(2*i+1)%2==0)
            a[i]=a[(i-1)/2]*10+7;
        else if(i%2!=0&&(2*i+1)%2!=0)
            a[i]=a[(i-1)/2]*10+4;
        else if(i%2==0&&(2*i+1)%2!=0)
            a[i]=a[(i-1)/2]*10+7;
        else if(i%2==0&&(2*i+1)%2==0)
            a[i]=a[(i-1)/2]*10+4;
            cout << a[i] << " " ;
        if(a[i]>n)
        {
            temp2=i-1;
            break;
        }
    }
//    for(int i=1; i<=temp2; i++)
//    {
//
//        cout << a[i] << " ";
//    }
    return 0;
}
