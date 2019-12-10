#include <iostream>

using namespace std;
float tong(int n)
{
    float s=0;
    for(int i=1;i<=n;i++)
        s+=float(1)/i;
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<tong(n);
    return 0;
}
