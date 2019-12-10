#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long a,b,tmp;
int n;
int main()
{
    ios::sync_with_stdio(false);
	cin>>n;
	//f
	a=2;
	b=1;
	for (int i=3;i<=n;i++) {
		tmp=(a+b)%MOD
		a=b;
		b=tmp;
	}
	if (n==1) cout<<2; else cout<<b;
}

