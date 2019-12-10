#include <iostream>

using namespace std;
int tonguoc(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0) s+=i;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<tonguoc(n);
    return 0;
}
