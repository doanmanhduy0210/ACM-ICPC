#include <iostream>
using namespace std;
int n,x[21];
void Xuli()
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void Try(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        if(i<n) 
            Try(i+1);
        else
            Xuli();
    }
}
int main()
{
    
    cin>>n;
    Try(1);    
}