// by Minglee
#include <bits/stdc++.h>
#define ll long long
#define eq =
#define eq1 ==
using namespace std;

const int maxn = 2e5+5;
ll a,b,c;
ll solve(ll a,ll b,ll c)
{
    if(b==0)
        return 1%c;// tru?ng h?p c b?ng 1

    if(b%2==0)
        return (solve(a,b/2,c)*solve(a,b/2,c)) % c;

    return (a*solve(a,b/2,c)*solve(a,b/2,c)) % c;
}
int main() {

	cin>>a>>b>>c;

	cout<< solve(a,b,c);
	return 0;
}
