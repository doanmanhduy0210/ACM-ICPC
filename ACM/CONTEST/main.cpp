#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define ll long long
const int maxn = 10101010;
const int N = 10000009;
typedef unsigned long long ull;

ll prime[maxn],m;

ull toLL(ll x,ll y)
{
    ull p = x;
    vector <int > curr;
    while(y>0)
    {
        curr.push_back(y%10);
        y/=10;
    }
    for(int i=curr.size()-1; i>=0; i--)
    {
        p = p*10 + curr[i];
    }
    return p;
}


ull pow(ull a , ull d, ull m)
{
    ull b;
    if (d==1) return a%m;
    b=pow(a,d/2,m);
    b=(b*b) %m;
    if (d%2 == 1) b=(b*a) % m;
    return b;
}
bool rabin( ull n)
{
    if (n == 2) return true;

    if (n < 2 || !(n & 1)) return false;

    const  ull p[3] = {3, 5, 7};

    ull a, d = n-1, mx = 3;

    int i, r, s = 0;

    while (!(d & 1))
    {
        ++s;
        d >>= 1;
    }

    for (i = 0; i < mx; ++i)
    {

        if (n == p[i]) return true;

        if (!(n % p[i])) return false;

        a = pow(p[i], d,n);

        if (a != 1)
        {
            for (r = 0; r < s && a != n-1; ++r) a = (a*a)%n;

            if (r == s) return false;
        }
    }
    return true;
}

void snt()
{
    for(ull i = 2; i<=N; i++)
    {
        if(rabin(i))
            prime[m++]=i;
    }
}
int main()
{
    freopen("output.txt","w",stdout);
   // snt();
    int k,cnt = 0;
    cin >> k;
   // cout << toLL(prime[m-2],prime[m-1])<<endl;
   cout << rabin(99999739999991);
//    for(int i=1; i<m ; i+=2)
//    {
//        ull x = toLL(prime[i-1],prime[i]);
//        if(rabin(x))
//            cnt ++,cout << x << " "<<cnt<<endl;;
//        if(cnt==k)
//            return cout << x,0;
//    }
    return 0;
}
