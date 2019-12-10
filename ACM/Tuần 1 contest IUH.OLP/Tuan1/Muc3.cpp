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

//chia so lon s cho 2 và phan du la x
string chia(string s,unsigned long long &x){
	long long n=s.length(),tmp=0;
	string s1;
	for (int i=0;i<n;i++){
		tmp=tmp*10+(s[i]-'0');
		if (tmp>1) s1+=char(tmp/2+'0'),tmp%=2; else 
		if (!s1.empty()) s1+='0';
	}
	if (s1.empty()) s1+='0';
	x=(s1[s1.length()-1]-'0')%2;
	return s1;
}

unsigned long long ans[2][2]={1,0,0,1},i2[2][2]={0,1,1,1},j=0;
string n;
int main()
{
    ios::sync_with_stdio(false);
	cin>>n;
	if (n[0]=='1'&&n.size()==1) cout<<2; else
	if (n[0]=='2'&&n.size()==1) cout<<1; else {
		j=(n[n.length()-1]-'0')%2;
		for (n;n[0]!='0';n=chia(n,j)) {
			if (j) nhan(ans,i2,ans);
			nhan(i2,i2,i2);
		}
		cout<<(MOD+(ans[1][0]*2+ans[1][1])%MOD-(ans[0][0]*2+ans[0][1])%MOD)%MOD;
	}
}

