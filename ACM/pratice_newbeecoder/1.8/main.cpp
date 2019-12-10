#include <iostream>

using namespace std;
bool snt(int n)
{
    if(n==2)return true;
    for(int i=2;i<=n/2;i++)
        if(n%i==0) return false;
    return true;
}
void insnt(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(snt(i)) cout<<i<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    insnt(n);
    return 0;
}
