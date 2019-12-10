#include <iostream>

using namespace std;
bool snt(int n)
{
    if(n==2)return true;
    for(int i=2;i<=n/2;i++)
        if(n%i==0) return false;
    return true;
}

int tongsnt(int n)
{
    int s=0;
    for(int i=2;i<=n;i++)
        if(snt(i)) s+=i;
    return s;
}
int main()
{
   int n;
   cin>>n;
   cout<<tongsnt(n);
    return 0;
}
