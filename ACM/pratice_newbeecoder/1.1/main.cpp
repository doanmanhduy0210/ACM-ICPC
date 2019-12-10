#include <iostream>

using namespace std;


long long gt(int n)
{
    long long s=1;
    for(long long i=2;i<=n;i++)
        s*=i;
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<gt(n);
    return 0;
}
