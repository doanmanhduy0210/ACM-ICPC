#include<bits/stdc++.h>
#define oo 123456
#define maxC 123456
using namespace std;
int a[5005][5005], c[5005][5005],d[1000];
bool check[1000];
int main()
{
    freopen("datain.txt","r",stdin);
    int T; cin>>T;
    while(T--)
    {
        int n,m,F; cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(a[u][v]==1)
            {
                c[u][v]=min(c[u][v],w);
                c[v][u]=c[u][v];
            }
            else
                {
                    c[u][v]=w;
                    c[v][u]=w;
                }
            a[u][v]=1;
            a[v][u]=1;
        }
        cin>>F;
        for(int u=0;u<n;u++)
        {
            if(a[u][F]==1)
                d[u]=c[u][F];
            else
                d[u]=oo;
        }
        d[F]=0;
        for(int i=0;i<n;i++)
            check[i]=true;
//
//            for(int i=0;i<n;i++)
//                cout<<d[i]<<endl;

        for(int u=0;u<n;u++)
        {
            int now=0,x=maxC;
            for(int v=0;v<n;v++)
            {
                if(d[v]<x&&d[v]!=oo&&check[v]&&v!=F)
                {
                    now=v;
                    x=d[v];
                }
            }
            //cout<<now<<" ";
            check[now]=false;
            if(now==F)
                break;
            for(int v=0;v<n;v++)
            {
                if(d[v]>max(d[now],c[v][now])&&check[v]&&a[now][v]==1)
                {
                    d[v]=max(d[now],c[v][now]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(d[i]!=oo)
                cout<<d[i]<<endl;
            else
                cout<<"Impossible"<<endl;
        }
    }
}
