#include <bits/stdc++.h>
#define maxn 5000
using namespace std;
int n,m,a[maxn][maxn],S,F;
bool check[maxn];
int Trace[maxn];
queue <int> q;
void BFS(int v)
{
    if(v==F||q.empty())
        return ;

    for(int i=1;i<=n;i++)
        if(a[S][i]==1)
        {
            q.push(i);
        }
    int u = q.front();
    q.pop();
    if(check[u])
    {
        Trace[u]=v;
        check[u]=false;
    }
    BFS(q.front());

}
int main()
{
    cin>>n>>m;
    cin>>S>>F;

    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        check[u]=true;
        check[v]=true;
        a[u][v]=1;
        a[v][u]=1;
    }
    BFS(S);
    return 0;
}
/*
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[2309];
int d[2309]; //one-based
int n, m;

void bfs(){
    int u, i, v;
    queue<int> qu;
    qu.push(1);
    d[1] = 1;

    while (qu.size()){
        u=qu.front();
        qu.pop();

        for (i=0; v=a[u][i]; i++)
        if (d[v]==0) {
            d[v]=d[u]+1;
            qu.push(v);
        }
    }

}

main(){
    int i, p, q;
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d", &p, &q);
        a[p].push_back(q);
        a[q].push_back(p);              // remove it in one-directional graph
    }
    for (i=1; i<=n; i++) a[i].push_back(0);
    bfs();
    printf("   i : "); for (i=1; i<=n; i++) printf("%3d,", i); printf("\n");
    printf("d[i] : "); for (i=1; i<=n; i++) printf("%3d,", d[i]); printf("\n");
}
*/
