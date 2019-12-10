#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6+6;
const int  inf  = 1e9 + 7;
const double pi = acos(-1.0);
const long long BASE = 1e9 +7;


string a,b;
int na,nb;
int k=26;
long long hasha[maxn];
long long hashb[maxn];
long long d[maxn];

void file()
{
    freopen("SUBSTR.inp", "r", stdin);
    freopen("SUBSTR.out", "w", stdout);
}

void enter()
{
    cin>>a;
    na=a.length();
    cin>>b;
    nb=b.length();
}

long long gethash(int i,int j)
{
    long long re=(hasha[j]-hasha[i-1]*d[j-i+1]+BASE*BASE)%BASE;
    return re;
}

long long gethash1(int i,int j)
{
    long long re=(hashb[j]-hashb[i-1]*d[j-i+1]+BASE*BASE)%BASE;
    return re;
}


void solve()
{
    d[0]=1;
    for (int i=1;i<=na;i++)
        d[i]=(d[i-1]*k)%BASE;
    a=" "+a;
    b=" "+b;
    hasha[0]=1;
    hashb[0]=1;
    for(int i = 1;i <= na ; i++ )
        hasha[i]=(hasha[i-1]*k+(int(a[i])-96)+BASE)%BASE;
    for (int i = 1;i <= nb ; i++ )
        hashb[i]=(hashb[i-1]*k+(int(b[i])-96)+BASE)%BASE;
    for (int i=1;i<=na-nb+1;i++)
        if (gethash(i,i+nb-1)==gethash1(1,nb))
            cout<<i<<" ";
}

int main()
{
   // file();
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    enter();
    solve();
}
