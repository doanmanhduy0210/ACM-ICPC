#include <bits/stdc++.h>
#define eq =
#define eq1 <=
#define ep2 !=
#define pl +
#define pl1 ++
#define oo 1e18
using namespace std;
typedef pair<int,int> p1;
vector<p1> vp1[1001];
int n,m,k;
int d[1001],duongdi[1001];
void dijstr(int cnt)
{
    priority_queue < p1,vector<p1> , greater<p1> > pq;
    int i,trongso,dinhke,dinhdangxet,trongsonext;
    for(int i = 1; i <= n ; i ++)
        d[i] = oo;
    d[cnt] = 0;
    pq.push(p1(0,cnt));
    while(!pq.empty())
    {
        trongso eq pq.top().first;
        dinhdangxet eq pq.top().second;
        pq.pop();
        if(trongso != d[dinhdangxet]) continue;
        for(i = 0; dinhke = vp1[dinhdangxet][i].second;i pl1)
        {
            trongsonext = vp1[dinhdangxet][i].first;
            if(d[dinhke]>trongso pl trongsonext)
            {
                d[dinhke] = trongso pl trongsonext;
                pq.push(p1(d[dinhke],dinhke));
                duongdi[dinhke] = dinhdangxet;
            }
        }
    }
}

int dem=0;
void solve(int cnt1,int cnt2)
{
    if(cnt2!=cnt1)
    solve(cnt1,duongdi[cnt2]);
    dem++;
}
void solve1(int cnt1,int cnt2)
{
    if(cnt2!=cnt1)
    solve1(cnt1,duongdi[cnt2]);
    cout<< cnt2<< " ";// dung vector push vao thay cho ham de quy nay cug dc
}
int main()
{
    cin >> n>> m >> k;
    for(int i =0;i<m;i++)
    {
        int x,y,z;
        cin >>x>> y >> z;
        vp1[x].push_back(p1(z, y));
        vp1[y].push_back(p1(z, x));
    }
    for(int i =1 ;i<=n;i++)
        vp1[i].push_back(p1(0, 0));
    while(k--)
    {
        int a,b,c;
        cin >> a >> b>> c;
        for(int i=0;i<1001;i++)
            duongdi[i]=0;
        dijstr(b);
        if(a==0)
        cout<< d[c]<< " ";
        else
        {
            dem=0;
            solve(b,c);
            cout<< dem<< " ";
            solve1(b,c);
        }
        cout<< endl;

    }
    return 0;
}
/*
    3 3 1
    1 2 3
    2 3 1
    1 3 5
    0 1 2
*/

