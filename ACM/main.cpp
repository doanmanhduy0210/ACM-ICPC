#include<bits/stdc++.h>
#define for1(i,a,b,c) for(int i=a;i<b;i+=c)
#define for2(i,b,a,c) for(int i=b-1;i>=a;i-=c)
#define setp(a) setprecision(a)
#define ll long long
#define fi first
#define sc second
using namespace std;
int a[1001][1001];
bool b[1001][1001];
int x[]={0,0,-1,1};
int y[]={-1,1,0,0};
int n,m;
bool solve(int cnt1,int cnt2)
{
    return cnt1>=1&&cnt1<=n&&cnt2>=1&&cnt2<=m;
}

int dfs(int cnt1,int cnt2)
{
    b[cnt1][cnt2]=true;

    for(int i=0;i<4;i++)
    {
        int fx=cnt1+x[i];
        int fy=cnt2+y[i];
        //cout <<fx << " "<< fy << endl;
        if(solve(fx,fy)&&!b[fx][fy]&&a[fx][fy]==0)
        {
            if(fx==n&&fy==m)
                return 1;
            return dfs(fx,fy);
        }
    }
    return -1;
}
int main()
{
    cin >> n>> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin >> a[i][j];
    cout << dfs(1,1);
    return 0;
}
