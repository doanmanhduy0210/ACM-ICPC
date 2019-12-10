#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//nhan ma tran a * b = c
void nhan(unsigned long long a[2][2], unsigned long long b[2][2], unsigned long long c[2][2]){
	//Bien tam
	unsigned long long tmp[2][2]={};
	
	//Nhan ma tran vao bien tam
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int o=0;o<2;o++)
				tmp[i][j]=(tmp[i][j]+a[i][o]*b[o][j])%MOD;
	
	//Chuyen bien tam vao ket qua		
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			c[i][j]=tmp[i][j];		
}

unsigned long long n,ans[2][2]={1,0,0,1},i2[2][2]={0,1,1,1};
int main()
{
    ios::sync_with_stdio(false);
	cin>>n;
	if (n==1) cout<<2; else
	if (n==2) cout<<1; else {
		//ly thua bang nhi phan
		for (unsigned long long i=n-2;i>0;i/=2) {
			if (i%2) nhan(ans,i2,ans);
			nhan(i2,i2,i2);
		}
		cout<<(ans[1][0]*2+ans[1][1])%MOD;
	}
}

