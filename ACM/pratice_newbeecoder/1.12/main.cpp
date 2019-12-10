#include <iostream>

using namespace std;
bool snt(int n)
{
    if(n==2)return true;
    for(int i=2;i<=n/2;i++)
        if(n%i==0) return false;
    return true;
}
int sntln(int n)
{
    for(int i=n-1;i>=2;i--)
        if(snt(i))
            return i;
    return -1;
}
int main()
{
    int n;
    cin>>n;
    cout<<sntln(sntln(n));
    return 0;
}
