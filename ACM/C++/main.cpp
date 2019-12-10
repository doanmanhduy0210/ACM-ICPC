#include<bits/stdc++.h>


#define vocuc 1e18
#define ll long long
using namespace std;

typedef pair<ll,int> ii;
// m?ng này là danh sách k?
vector<ii> arr[100005];
int n,m;
// m?ng này này là giá tr? gán lúc d?u là vô  c?c khi chua xét d?nh
ll d[100005];

ll duongdi[100005];
void solve(int cnt)
{
    if(cnt!=1)
    solve(duongdi[cnt]);
    cout<< cnt << " ";
}
void dijstra()
{
    // dùng priority
    // th?ng này nó ho?t d?ng nhu stack . m?c dù là queue nhung nó k có front mà ch? có top
    // dùng greater nó m?c d?nh ph?n t? top luôn mà min còn k dùng thì là max
    priority_queue<ii , vector<ii > ,greater<ii > > pq;
    ll v,uv;
    // kh?i t?o vô c?c c?a m?ng d
    for(int i=1;i<=n;i++)
    d[i] =vocuc;
    // d?nh b?t d?u thì giá tr? c?a d[0] là 0
    d[1] = 0;

    pq.push(ii(1,0));
    int dinhke,dinhdangxet,trongso;
    while(pq.size())
    {

        dinhdangxet = pq.top().first;
        trongso = pq.top().second;
        pq.pop();


        if (trongso!=d[dinhdangxet]) continue;

        for (int i=0; dinhke=arr[dinhdangxet][i].first; i++)
        {
            //cout<< u<< " ";
            //cout<< arr[u][i].first << " "<< arr[u][i].second << " " << i<< endl;
            // arr[u][i].first là tr?ng s? c?a d?nh
            //int dinhke=arr[dinhdangxet][i].first;
            //int temp2=arr[dinhdangxet][i].second;
            int trongsodangxet = arr[dinhdangxet][i].second;
            if (d[dinhke]>trongso+trongsodangxet) {
                d[dinhke]=trongso+trongsodangxet;
                pq.push(ii(dinhke,d[dinhke]));
            //cout<< dinhke<< " "<< dinhdangxet<< endl;
                duongdi[dinhke]=dinhdangxet;

            }

        }



    }

}

int main()
{

    int p, q,  w;
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d", &p, &q, &w);
        arr[p].push_back(ii(q, w));
        arr[q].push_back(ii(p, w));
    }
    for (int i=1; i<=n; i++) arr[i].push_back(ii(0,0));

    dijstra();
//    for(int i=1;i<=n;i++)
//    cout<< d[i]<< " ";
    if(d[n]==vocuc)
        cout<< -1;
    else
        {
            solve(n);

        }



}
