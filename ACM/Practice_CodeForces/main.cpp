#include <bits/stdc++.h>
using  namespace std;
#define maxsize 55
#define maxn 555
#define ll long long
#define For(i,x,y) for(int i=x; i<y; i++)
#include <iostream>
#define mod 10e9 + 7


int n,m,a[maxn][maxn],cnt,b[maxn][maxn];
pair <int,int> ans[maxn];


int main()
{
    cin >> n >> m;
    For(i,1,n+1) For(j,1,m+1) cin >> a[i][j];

    For(i,1,n+1) For(j,1,m+1)
    {
        if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
        {
            b[i][j] = 1, b[i+1][j] = 1,b[i][j+1] = 1, b[i+1][j+1] = 1;
            ans[cnt].first = i;
            ans[cnt].second = j;
            cnt ++;
        }
    }

    For(i,1,n+1)For(j,1,m+1)
    {
        if(a[i][j]!=b[i][j]) return cout << -1,0;
    }
    cout << cnt <<endl;
    For(i,0,cnt)
    {
        cout << ans[i].first <<" "<<ans[i].second << endl;
    }
    return 0;
}
