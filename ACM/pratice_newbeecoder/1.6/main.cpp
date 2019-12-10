#include <iostream>

using namespace std;
void tc_tl(int n)
{
    int tc=0,tl=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0) tc+=i;
        else tl+=i;
    }
    cout<<tc<<endl;
    cout<<tl<<endl;
}
int main()
{
    int n;
    cin>>n;
    tc_tl(n);
    return 0;
}
