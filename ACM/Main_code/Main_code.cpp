#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const long long MOD = 1e9+7;
const int maxn = 2e5+7;
int n;
int a[maxn],q[maxn],c[maxn];
set<int> m;
int main()
{
    long long n,m,cnt=0, p ,z;
    cin >> n >> m;
    if(m%n!=0)
        return cout << -1,0;
    p = m/n, z = p;
    while(z%6==0)
    {
        z/=6;
        cnt +=2;
    }
    while(z%3==0)
    {
        z/=3;
        cnt++;
    }
    while(z%2==0)
    {
        z/=2;
        cnt++;
    }

    if(z!=1) cout<<-1;
    else
        cout << cnt;
}

